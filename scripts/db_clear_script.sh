#!/bin/bash


# usage: db_clear_script.sh [dump_filename] [output_filename] [db_name] [db_user] [db_password]
USAGE_INFO="Usage: db_clear_script.sh [dump_filename] [output_filename] [db_name] [db_user] [db_password]"
clear
echo "==================="
echo "Droptica database script - clear users and nodes"
echo "==================="
echo "Starting..."
#Get parameters
PARAM_DUMP_FILENAME=${1}
PARAM_OUTPUT_FILENAME=${2}
PARAM_DB_NAME=${3}
PARAM_DB_USER=${4}
PARAM_DB_PASSWORD=${5}


# Check parameters.
if [ -z $PARAM_DUMP_FILENAME ]; then echo "PARAM_DUMP_FILENAME is empty. Exiting $USAGE_INFO"; exit 1; fi;
if [ -z $PARAM_OUTPUT_FILENAME ]; then echo "PARAM_OUTPUT_FILENAME is empty. Exiting $USAGE_INFO"; exit 1; fi;
if [ -z $PARAM_DB_NAME ]; then echo "PARAM_DB_NAME is empty. Exiting $USAGE_INFO"; exit 1; fi;
if [ -z $PARAM_DB_USER ]; then echo "PARAM_DB_USER is empty. Exiting $USAGE_INFO"; exit 1; fi;
if [ -z $PARAM_DB_PASSWORD ]; then echo "PARAM_DB_PASSWORD is empty. Exiting $USAGE_INFO"; exit 1; fi;

echo "Clear current database..."
mysqldump --user=$PARAM_DB_USER --password=$PARAM_DB_PASSWORD --add-drop-table --no-data $PARAM_DB_NAME | grep ^DROP | mysql -u$PARAM_DB_USER -p$PARAM_DB_PASSWORD $PARAM_DB_NAME

echo "Import file to database..."
mysql $PARAM_DB_NAME < $PARAM_DUMP_FILENAME -u$PARAM_DB_USER -p$PARAM_DB_PASSWORD
echo "SQL commands..."

mysql $PARAM_DB_NAME -e "
UPDATE users SET mail = CONCAT(SUBSTRING(MD5(name), 1, 9), '@localhost'), init = CONCAT(SUBSTRING(MD5(name), 1, 9), '@localhost'), pass = MD5(CONCAT('123', name));

UPDATE users SET name = CONCAT(SUBSTRING(MD5(name), 1, 9));

DELETE FROM users WHERE uid > 15;

UPDATE field_data_field_user_about_me SET field_user_about_me_value = CONCAT(SUBSTRING(MD5(field_user_about_me_value), 1, 9));
UPDATE field_revision_field_user_about_me SET field_user_about_me_value = CONCAT(SUBSTRING(MD5(field_user_about_me_value), 1, 9));

UPDATE field_data_field_user_first_name SET field_user_first_name_value = CONCAT(SUBSTRING(MD5(field_user_first_name_value), 1, 9));
UPDATE field_revision_field_user_first_name SET field_user_first_name_value = CONCAT(SUBSTRING(MD5(field_user_first_name_value), 1, 9));

UPDATE field_data_field_user_job_title SET field_user_job_title_value = CONCAT(SUBSTRING(MD5(field_user_job_title_value), 1, 9));
UPDATE field_revision_field_user_job_title SET field_user_job_title_value = CONCAT(SUBSTRING(MD5(field_user_job_title_value), 1, 9));

UPDATE field_data_field_user_last_name SET field_user_last_name_value = CONCAT(SUBSTRING(MD5(field_user_last_name_value), 1, 9));
UPDATE field_revision_field_user_last_name SET field_user_last_name_value = CONCAT(SUBSTRING(MD5(field_user_last_name_value), 1, 9));

UPDATE field_data_field_user_organization SET field_user_organization_value = CONCAT(SUBSTRING(MD5(field_user_organization_value), 1, 9));
UPDATE field_revision_field_user_organization SET field_user_organization_value = CONCAT(SUBSTRING(MD5(field_user_organization_value), 1, 9));



TRUNCATE cache;
TRUNCATE cache_admin_menu;
TRUNCATE cache_block;
TRUNCATE cache_bootstrap;
TRUNCATE cache_field;
TRUNCATE cache_filter;
TRUNCATE cache_form;
TRUNCATE cache_image;
TRUNCATE cache_libraries;
TRUNCATE cache_page;
TRUNCATE cache_path;
TRUNCATE cache_rules;
TRUNCATE cache_token;
TRUNCATE cache_update;
TRUNCATE cache_variable;
TRUNCATE cache_views;
TRUNCATE cache_views_data;

TRUNCATE captcha_sessions;


TRUNCATE TABLE sessions ;
TRUNCATE TABLE sessions ;
TRUNCATE watchdog;

DELETE FROM url_alias WHERE source LIKE '%user%'


" --user=$PARAM_DB_USER --password=$PARAM_DB_PASSWORD


echo "Exporting database to file $PARAM_OUTPUT_FILENAME..."
mysqldump $PARAM_DB_NAME > $PARAM_OUTPUT_FILENAME -u$PARAM_DB_USER -p$PARAM_DB_PASSWORD
echo "Done"
echo "==================="

