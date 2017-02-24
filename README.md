These scripts and this C program help with the diagnotics of faulty internet connections in Linux systems. I'm sure that something like these must already exist but I created it anyway just for purposes of learning. It should prove itself useful for test connections for example when you lack a GUI. Here goes the step by step:

1 - activate the startPings.sh
This script activates pings for three hosts: the local gateway, a neighbour gateway and google's DNS server. Of course these are configured for my personal network so if you would test these by yourself you'll have to change these IP values.

2 - activate the stopPings.sh 
This will kill all three processes after you gathered enough data. At least some hours. You can do it manually via terminal also.

3 - activate the cleanOutputFiles.sh
This script uses a bunch of sed commands that leave the files ready to be analysed by the C program. In this concern it is important to say that the clean will work properly only on files created with ping commands of the Debian Jessie Version. If the output doesn't match this structure:

 int     int      int        int         float
[hour] [minute] [second] [pingNumber] [replyTime]

the clean wont work and therefore nor will the C program.

4 - compile and execute the analyser.c program
This program shows a bunch of statistcs for the local conexion. Total number of pings for each host, time for begining and end of tests and some other things. The most important is the doAnalysis() function. This one calculates how many sucessfull pings occured by minute for each host showing the periods of time in wich the conection was lost. In this case, pings to the local gateway normally dont fail, pings to the neighbour gateway might, and pings to Google have a bigger chance of failing.


To do:
* make a nice Menu for the program
* make some adjustments that allow for the user to select wich time periods he or she want to analyse
* make some kind of overlapping function that compares the results for each host
* make some objective function that returns the faulty periods immediatly
* make some adjustments to allow big outputs files that analyse many days intead of hours
* more tests

