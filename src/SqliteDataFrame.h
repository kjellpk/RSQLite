#define STRICT_R_HEADERS
#define R_NO_REMAP


#ifndef RSQLITE_SQLITEDATAFRAME_H
#define RSQLITE_SQLITEDATAFRAME_H

#include "sqlite3.h"
#include "DbDataFrame.h"

class SqliteDataFrame : public DbDataFrame {
public:
  SqliteDataFrame(sqlite3_stmt* stmt, std::vector<std::string> names, const int n_max_, const std::vector<DATA_TYPE>& types,
                  bool with_alt_types);
  virtual ~SqliteDataFrame();
};

#endif //RSQLITE_SQLITEDATAFRAME_H
