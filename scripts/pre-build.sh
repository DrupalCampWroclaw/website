echo "==================="
echo "Pre-build script start"

#FILES
if [ -d $PARAM_PROJECT_PATH_APP"/sites/default/files" ]; then
  rm -rf $PARAM_PROJECT_PATH_APP"/sites/default/files"
  RESULT=$(($RESULT+$?))
fi
tar -xzf files/files.tar.gz -C $PARAM_PROJECT_PATH_APP"/sites/default/"
RESULT=$(($RESULT+$?))
chmod -R 777 $PARAM_PROJECT_PATH_APP"/sites/default/files"


echo "Pre-build script end"
echo "==================="
