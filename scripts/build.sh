#!/bin/bash

clear
res1=$(date +%s.%N)
echo "==================="
echo "Drupal build script"
echo "-- Created by DROPTICA - www.droptica.com"
echo "-- Script version: 2013-08-27.01"
echo "Usage:"
echo "./build.sh without parameters assumes you have everything set up in conf/local"
echo "./build.sh PARAMETERS param1 param2 param3 - lets you enter parameters manually"
echo "==================="
echo "Starting ..."

RESULT=0

echo "Loading config..."

if [ -e "./conf/local/conf.inc" ]; then
  echo "Loading config file: "$(dirname $0)"/../conf/local/conf.inc"
  source $(dirname $0)"/../conf/local/conf.inc"
else
  echo "Missing file ./conf/local/conf.inc"
  echo "Error, exiting."
  exit;
fi
RESULT=$(($RESULT+$?))
if [ $RESULT = 1 ]; then
  exit 1
fi

PARAM_PROJECT_PATH_APP=$PARAM_PROJECT_PATH"/"$PARAM_DRUPAL_LOCATION
echo "Parameters: "
echo "- PARAM_PROJECT_PATH: ${PARAM_PROJECT_PATH}"
echo "- PARAM_PROJECT_PATH_APP: ${PARAM_PROJECT_PATH_APP}"
echo "- PARAM_SITE_URI: ${PARAM_SITE_URI}"
echo "- PARAM_SITE_DIRECTORY (sites/PARAM_SITE_DIRECTORY/settings.php): ${PARAM_SITE_DIRECTORY}"

source $(dirname $0)/"git-hooks.inc.sh"

echo "settings.php file"
if [ -f $PARAM_PROJECT_PATH_APP"/sites/"$PARAM_SITE_DIRECTORY"/settings.php" ]; then
  chmod 777 $PARAM_PROJECT_PATH_APP"/sites/"$PARAM_SITE_DIRECTORY"/settings.php"
  rm $PARAM_PROJECT_PATH_APP"/sites/"$PARAM_SITE_DIRECTORY"/settings.php"
  RESULT=$(($RESULT+$?))
  if [ $RESULT = 1 ]; then
    echo "Error, exiting."
    exit 1
  fi
fi
if [ -e $PARAM_PROJECT_PATH"/conf/local/settings.php" ]
  then
    cp $PARAM_PROJECT_PATH"/conf/local/settings.php" $PARAM_PROJECT_PATH_APP"/sites/"$PARAM_SITE_DIRECTORY"/settings.php"
  else
    echo "you are missing a settings.php file in ${PARAM_PROJECT_PATH}/conf/local"
    RESULT = 1
fi
RESULT=$(($RESULT+$?))
if [ $RESULT = 1 ]; then
  exit 1
fi

echo "drush sql-drop"
drush -r $PARAM_PROJECT_PATH_APP sql-drop -y

# Pre build
source $(dirname $0)"/pre-build.sh"

#Instructions for new project
if [ $PARAM_PROJECT_IS_NEW = "yes" ];
then
  echo "Install site"
  # drush -r $PARAM_PROJECT_PATH_APP si $PARAM_INSTALLATION_PROFILE -y
  drush -r $PARAM_PROJECT_PATH_APP si $PARAM_INSTALLATION_PROFILE --site-name="${PARAM_SITE_NAME}" --site-mail=admin@droptica.com -y

  echo "drush cc all"
  drush -r $PARAM_PROJECT_PATH_APP cc all
fi

#Instructions for existing project
if [ $PARAM_PROJECT_IS_NEW = "no" ];
then
  echo "Import Drupal database $PARAM_DBDUMP_DRUPAL"
  tar xfzO ./databases/$PARAM_DBDUMP_FILE | mysql  -u$PARAM_DBUSER -p$PARAM_DBPASS $PARAM_DBNAME_DRUPAL

  echo "drush updb"
  drush -r $PARAM_PROJECT_PATH_APP updb -y
fi

# Post build
source $(dirname $0)"/post-build.sh"

# Set admin name and password
echo "Set admin login: "${PARAM_ADMIN_NAME}
drush -r $PARAM_PROJECT_PATH_APP sql-query "UPDATE users SET name='${PARAM_ADMIN_NAME}' WHERE uid=1"
echo "Set admin password: "${PARAM_ADMIN_PASS}
drush -r $PARAM_PROJECT_PATH_APP user-password $PARAM_ADMIN_NAME --password="${PARAM_ADMIN_PASS}"

drush -r $PARAM_PROJECT_PATH_APP --uri=$PARAM_SITE_URI uli
