/*
 *  Template MIB group interface - extensible.h
 *
 */
#ifndef _MIBGROUP_EXTENSIBLE_H
#define _MIBGROUP_EXTENSIBLE_H

config_require(util_funcs)
  
struct extensible *get_exten_instance __P((struct extensible *, int));
unsigned char *var_extensible_shell __P((struct variable *, oid *, int *, int, int *, int (**write) __P((int, u_char *, u_char, int, u_char *, oid *, int)) ));
int fixExecError __P((int, u_char *, u_char, int, u_char *, oid *,int));
unsigned char *var_extensible_relocatable __P((struct variable *, oid *, int *, int, int *, int (**write) __P((int, u_char *, u_char, int, u_char *, oid *, int)) ));
struct subtree *find_extensible __P((struct subtree *, oid *, int, int));

/* config file parsing routines */
void extensible_free_config __P((void));
void extensible_parse_config __P((char *, char *));
config_parse_dot_conf("exec", extensible_parse_config, extensible_free_config, "[miboid] name program arguments")
config_parse_dot_conf("sh", extensible_parse_config, extensible_free_config,"[miboid] name program-or-script arguments")

#include "mibdefs.h"

#define SHELLCOMMAND 3
#define SHELLRESULT 6
#define SHELLOUTPUT 7

#ifdef IN_SNMP_VARS_C

struct variable2 extensible_extensible_variables[] = {
  {MIBINDEX, ASN_INTEGER, RONLY, var_extensible_shell, 1, {MIBINDEX}},
  {ERRORNAME, ASN_OCTET_STR, RONLY, var_extensible_shell, 1, {ERRORNAME}}, 
  {SHELLCOMMAND, ASN_OCTET_STR, RONLY, var_extensible_shell, 1, {SHELLCOMMAND}}, 
  {ERRORFLAG, ASN_INTEGER, RONLY, var_extensible_shell, 1, {ERRORFLAG}},
  {ERRORMSG, ASN_OCTET_STR, RONLY, var_extensible_shell, 1, {ERRORMSG}},
  {ERRORFIX, ASN_INTEGER, RWRITE, var_extensible_shell, 1, {ERRORFIX }}
};

config_load_mib(EXTENSIBLEMIB.SHELLMIBNUM.1, EXTENSIBLENUM+2, extensible_extensible_variables)

#endif
#endif /* _MIBGROUP_EXTENSIBLE_H */
