/*
 * This file is part of the trojan project.
 * Trojan is an unidentifiable mechanism that helps you bypass GFW.
 * Copyright (C) 2017-2020  The Trojan Authors.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _AUTHENTICATOR_H_
#define _AUTHENTICATOR_H_

#ifdef ENABLE_MYSQL
#include <mysql.h>
#endif // ENABLE_MYSQL
#include "config.h"
#include "sstatus.h"

class Authenticator {
private:
    enum {
        PASSWORD_LENGTH=56
    };
    bool is_valid_password(const std::string &password);
public:
    #ifdef ENABLE_MYSQL
        MYSQL con;
    #endif // ENABLE_MYSQL
    Authenticator(const Config &config);
    bool auth(const std::string &password, uint64_t &user_id, uint64_t &transfer_enable, uint64_t &bandwidth_used,  const Config &config, SStatus &sstatus);
    void record(const std::string &password,  SStatus &sstatus, uint64_t download, uint64_t upload, const Config &config);
    ~Authenticator();
};

#endif // _AUTHENTICATOR_H_
