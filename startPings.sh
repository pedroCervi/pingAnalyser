

mkdir -p pingsOutputs


ping 192.168.1.1 | perl -nle 'BEGIN {$|++} print scalar(localtime), " ", $_' > pingsOutputs/pingGate.txt &
ping 201.2.215.1 | perl -nle 'BEGIN {$|++} print scalar(localtime), " ", $_' > pingsOutputs/pingNeighbour.txt &
ping 8.8.8.8 | perl -nle 'BEGIN {$|++} print scalar(localtime), " ", $_' > pingsOutputs/pingGoogle.txt &


