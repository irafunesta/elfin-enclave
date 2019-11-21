/*
	ASCII Rogue-like game
*/
#include <iostream>
#include <string>
//#include "Game.h"
#include <dos.h>
#include <chrono>
#include <ctime>

#include "windows.h"
#include "StupidGame.h"
#include "sqlite3/sqlite3.h"

/*
	Store for later
	//std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point current = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> elapsed = current - lastTime;

*/

static int callback(void *data, int argc, char **argv, char **azColName) 
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

int main()
{	
	StupidGame Game;
	Game.Start();

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	std::string sql = "CREATE TABLE COMPANY("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"NAME           TEXT    NOT NULL," \
		"AGE            INT     NOT NULL," \
		"ADDRESS        CHAR(50)," \
		"SALARY         REAL );";

	std::string sql2 = "SELECT * FROM COMPANY;";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

	sqlite3_close(db);
	
	while (!Game.IsGameOver())
	{
		Game.ParseInput();		
		Game.Update();
		//Game.GameEnd();
	}

	std::cout << "Game Over" << std::endl;
	system("PAUSE");
	return 0;
}