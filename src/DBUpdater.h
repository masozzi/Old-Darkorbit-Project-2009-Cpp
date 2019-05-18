#pragma once
#ifndef __DBUPDATER_H__
#define __DBUPDATER_H__
#include <iostream>
#include <utility>
#include <string>

extern "C" {
#include <mysql.h>
}

#include "Defines.h"
#include "DBGetter.h"
extern "C" {

	//for the sake of this being the first version, i will just make it execute queries it types in
	class CDBUpdater
	{

		/* User Information */
		id_t  id;
		char* id_str; //"clanID","id", etc.;a clear representation of the primary key name
		char* column;
		char* from;
		char* set_value;
	public:
		CDBUpdater(char* column, char* table, char* id_str,
				id_t id) : id(id), id_str(id_str), column(column), from(table)
				{ }

		void changeQuery(char* column, char* table, char* id_str, id_t id, char* set_value);
		void changeColumn(char* column);
		void changeTable(char* table);
		void changeIdString(char* id_str);
		void changeId(id_t id);
		void changeSetValue(std::string t);

		/* Sets up a query in the scheme of 'UPDATE table SET row = value WHERE id = id_value' */
		void queryUpdate(void);
		/* Use at your own risk. no extras are going to save you from syntax errors*/
		void queryUpdateRaw(std::string& str,bool canReconnect = true);

		


	private:
		/*
		scheme: SELECT x FROM y WHERE id = z ORDER BY id ASC
		*/
		void print_db_err(const char*);
		bool execute(bool canReconnect = true);
	};
}

#endif
