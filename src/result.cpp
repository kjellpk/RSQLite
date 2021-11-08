#define STRICT_R_HEADERS
#define R_NO_REMAP

#include "pch.h"
#include "RSQLite_types.h"


#include "cpp11.hpp"
#include <cpp11/R.hpp>


//#include "DbResult.h"


[[cpp11::register]]
XPtr<DbResult> result_create(XPtr<DbConnectionPtr> con, std::string sql) {
  (*con)->check_connection();
  DbResult* res = SqliteResult::create_and_send_query(*con, sql);
  return XPtr<DbResult>(res, true);
}

[[cpp11::register]]
void result_release(XPtr<DbResult> res) {
  res.release();
}

[[cpp11::register]]
bool result_valid(XPtr<DbResult> res_) {
  DbResult* res = res_.get();
  return res != NULL && res->is_active();
}

[[cpp11::register]]
List result_fetch(DbResult* res, const int n) {
  return res->fetch(n);
}

[[cpp11::register]]
void result_bind(DbResult* res, List params) {
  res->bind(params);
}

[[cpp11::register]]
bool result_has_completed(DbResult* res) {
  return res->complete();
}

[[cpp11::register]]
int result_rows_fetched(DbResult* res) {
  return res->n_rows_fetched();
}

[[cpp11::register]]
int result_rows_affected(DbResult* res) {
  return res->n_rows_affected();
}

[[cpp11::register]]
List result_column_info(DbResult* res) {
  return res->get_column_info();
}

[[cpp11::register]]
CharacterVector result_get_placeholder_names(SqliteResult* res) {
  return res->get_placeholder_names();
}
