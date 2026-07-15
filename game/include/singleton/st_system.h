#ifndef SINGLETON_SYSTEM_H
#define SINGLETON_SYSTEM_H

#include <config/c_pch.h>
#include <dto/dto_curl.h>
#include <engine/e_variant.h>
#include <namespace/n_callback.h>
#include <namespace/n_file.h>

// HARUS MENYIMPAN ATRIBUT PLAYER

class SINGLETON_system {
public:
  SINGLETON_system();

  CURL *get_curl();
  void set_curl(CURL *value);

  std::string *get_access_token();
  void set_access_token(std::string *value);

  std::vector<std::pair<std::string, VariantType>> get_attribute();
  void set_attribute(std::vector<std::pair<std::string, VariantType>> value);

  std::string *auth_login(DtoCurl curlDto);

  std::vector<std::pair<std::string, VariantType>> get_fetch(DtoCurl curlDto);
  void set_post(DtoCurl curlDto);

private:
  CURL *curl;
  std::string *access_token;

  std::vector<std::pair<std::string, VariantType>> attribute;
};

extern SINGLETON_system *G_system;

#endif
