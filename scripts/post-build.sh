echo "==================="
echo "Post-build script start"

# Add custom code here
# for example: enable initcontent module

#echo "drush fra"
#drush -r $PARAM_PROJECT_PATH_APP fra -y

#echo "drush en file_redirect"
#drush -r $PARAM_PROJECT_PATH_APP en file_redirect -y
#drush -r $PARAM_PROJECT_PATH_APP php-eval "variable_set('file_redirect_production_host', 'http://www.drupalcampwroclaw.pl');"
#drush -r $PARAM_PROJECT_PATH_APP php-eval " file_redirect_create_htaccess();"


#echo "drush en initcontent"
#drush -r $PARAM_PROJECT_PATH_APP en initcontent -y

echo "Post-build script end"
echo "==================="
