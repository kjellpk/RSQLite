#define STRICT_R_HEADERS
#define R_NO_REMAP

#ifndef RPOSTGRES_INTEGER64_H
#define RPOSTGRES_INTEGER64_H

#define INT64SXP REALSXP

#define NA_INTEGER64 (int64_t(0x8000000000000000))

inline int64_t* INTEGER64(SEXP x) {
  return reinterpret_cast<int64_t*>(REAL(x));
}

#endif // RPOSTGRES_INTEGER64_H
