ps -ef | grep ping | grep -v grep | awk '{print $2}' | xargs kill
