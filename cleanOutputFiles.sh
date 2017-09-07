#delete pings that were marked unreacheable creating the first mod file
sed '/Destination Net Unreachable/d' pingsOutputs/pingGate.txt > pingsOutputs/pingGateModOne.txt
sed '/Destination Net Unreachable/d' pingsOutputs/pingNeighbour.txt > pingsOutputs/pingNeighbourModOne.txt
sed '/Destination Net Unreachable/d' pingsOutputs/pingGoogle.txt > pingsOutputs/pingGoogleModOne.txt

#selects only the necessary fields from raw outputs creating the second mod file
awk '{ print $4 $10 $12 }' pingsOutputs/pingGateModOne.txt > pingsOutputs/pingGateModTwo.txt
awk '{ print $4 $10 $12 }' pingsOutputs/pingNeighbourModOne.txt > pingsOutputs/pingNeighbourModTwo.txt
awk '{ print $4 $10 $12 }' pingsOutputs/pingGoogleModOne.txt > pingsOutputs/pingGoogleModTwo.txt

#do some editing inside the modified files
sed -i -e "1d" pingsOutputs/pingGateModTwo.txt
sed -r -i '/Host/ d' pingsOutputs/pingGateModTwo.txt
sed -i 's/icmp_seq=/ /g' pingsOutputs/pingGateModTwo.txt
sed -i 's/time=/ /g' pingsOutputs/pingGateModTwo.txt
sed -i 's/:/ /g' pingsOutputs/pingGateModTwo.txt
sed -r -i 's/^/ /g' pingsOutputs/pingGateModTwo.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingGateModTwo.txt
sed -r -i 's/.//' pingsOutputs/pingGateModTwo.txt

sed -i -e "1d" pingsOutputs/pingNeighbourModTwo.txt
sed -r -i '/Host/ d' pingsOutputs/pingNeighbourModTwo.txt
sed -i 's/icmp_seq=/ /g' pingsOutputs/pingNeighbourModTwo.txt
sed -i 's/time=/ /g' pingsOutputs/pingNeighbourModTwo.txt
sed -i 's/:/ /g' pingsOutputs/pingNeighbourModTwo.txt
sed -r -i 's/^/ /g' pingsOutputs/pingNeighbourModTwo.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingNeighbourModTwo.txt
sed -r -i 's/.//' pingsOutputs/pingNeighbourModTwo.txt

sed -i -e "1d" pingsOutputs/pingGoogleModTwo.txt
sed -r -i '/Host/ d' pingsOutputs/pingGoogleModTwo.txt
sed -i 's/icmp_seq=/ /g' pingsOutputs/pingGoogleModTwo.txt
sed -i 's/time=/ /g' pingsOutputs/pingGoogleModTwo.txt
sed -i 's/:/ /g' pingsOutputs/pingGoogleModTwo.txt
sed -r -i 's/^/ /g' pingsOutputs/pingGoogleModTwo.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingGoogleModTwo.txt
sed -r -i 's/.//' pingsOutputs/pingGoogleModTwo.txt
