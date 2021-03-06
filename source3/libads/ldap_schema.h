/*
   Unix SMB/CIFS implementation.
   ads (active directory) utility library
   Copyright (C) Guenther Deschner 2005-2007
   Copyright (C) Gerald (Jerry) Carter 2006

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _LIBADS_LDAP_SCHEMA_H_
#define _LIBADS_LDAP_SCHEMA_H_

/* used to remember the names of the posix attributes in AD */
/* see the rfc2307 & sfu nss backends */

struct posix_schema {
	char *posix_homedir_attr;
	char *posix_shell_attr;
	char *posix_uidnumber_attr;
	char *posix_gidnumber_attr;
	char *posix_gecos_attr;
	char *posix_uid_attr;
};

enum wb_posix_mapping {
	WB_POSIX_MAP_UNKNOWN    = -1,
	WB_POSIX_MAP_TEMPLATE 	= 0,
	WB_POSIX_MAP_SFU 	= 1,
	WB_POSIX_MAP_SFU20 	= 2,
	WB_POSIX_MAP_RFC2307 	= 3,
	WB_POSIX_MAP_UNIXINFO	= 4
};

/* The following definitions come from libads/ldap_schema.c  */

const char *ads_get_attrname_by_guid(ADS_STRUCT *ads,
				     const char *schema_path,
				     TALLOC_CTX *mem_ctx,
				     const struct GUID *schema_guid);
ADS_STATUS ads_schema_path(ADS_STRUCT *ads, TALLOC_CTX *mem_ctx, char **schema_path);
ADS_STATUS ads_check_posix_schema_mapping(TALLOC_CTX *mem_ctx,
					  ADS_STRUCT *ads,
					  enum wb_posix_mapping map_type,
					  struct posix_schema **s ) ;

#endif /* _LIBADS_LDAP_SCHEMA_H_ */
