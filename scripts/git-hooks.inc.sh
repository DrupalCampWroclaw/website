#!/bin/sh
#CREATE SYMLINK FOR GIT HOOKS

echo "==================="
echo "Git-hooks script start"
echo "-- Script version: 2013-08-21.02"

echo "GIT hook commit-msg"
if [ -f $PARAM_PROJECT_PATH"/.git/hooks/commit-msg" ]; then
  echo "commit-msg exists - removing"
  rm -rf $PARAM_PROJECT_PATH"/.git/hooks/commit-msg"
  RESULT=$(($RESULT+$?))
fi
ln -s $PARAM_PROJECT_PATH"/scripts/git-hooks/commit-msg" $PARAM_PROJECT_PATH"/.git/hooks/commit-msg"

echo "GIT hook pre-commit"
if [ -f $PARAM_PROJECT_PATH"/.git/hooks/pre-commit" ]; then
  echo "pre-commit exists - removing"
  rm -rf $PARAM_PROJECT_PATH"/.git/hooks/pre-commit"
  RESULT=$(($RESULT+$?))
fi
ln -s $PARAM_PROJECT_PATH"/scripts/git-hooks/pre-commit" $PARAM_PROJECT_PATH"/.git/hooks/pre-commit"
chmod +x $PARAM_PROJECT_PATH"/scripts/git-hooks/pre-commit"


echo "Git-hooks script end"
echo "==================="
