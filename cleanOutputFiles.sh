#selects only the necessary fields from raw outputs creating modified files
awk '{ print $4 $10 $12 }' pingsOutputs/pingGate.txt > pingsOutputs/pingGateMod.txt
awk '{ print $4 $10 $12 }' pingsOutputs/pingNeighbour.txt > pingsOutputs/pingNeighbourMod.txt
awk '{ print $4 $10 $12 }' pingsOutputs/pingGoogle.txt > pingsOutputs/pingGoogleMod.txt

#do some editing inside the modified files
sed -i -e "1d" pingsOutputs/pingGateMod.txt
sed -r -i '/Host/ d' pingsOutputs/pingGateMod.txt
sed -i 's/icmp_seq=/ /g' pingsOutputs/pingGateMod.txt
sed -i 's/time=/ /g' pingsOutputs/pingGateMod.txt
sed -i 's/:/ /g' pingsOutputs/pingGateMod.txt
sed -r -i 's/^/ /g' pingsOutputs/pingGateMod.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingGateMod.txt
sed -r -i 's/.//' pingsOutputs/pingGateMod.txt

sed -i -e "1d" pingsOutputs/pingNeighbourMod.txt
sed -r -i '/Host/ d' pingsOutputs/pingNeighbourMod.txt
sed -i 's/icmp_seq=/ /g' pingsOutputs/pingNeighbourMod.txt
sed -i 's/time=/ /g' pingsOutputs/pingNeighbourMod.txt
sed -i 's/:/ /g' pingsOutputs/pingNeighbourMod.txt
sed -r -i 's/^/ /g' pingsOutputs/pingNeighbourMod.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingNeighbourMod.txt
sed -r -i 's/.//' pingsOutputs/pingNeighbourMod.txt

sed -i -e "1d" pingsOutputs/pingGoogle.txt
sed -r -i '/Host/ d' pingsOutputs/pingGoogleMod.txt
sed -i 's/icmp_seq=/ /g' pingsOutputs/pingGoogleMod.txt
sed -i 's/time=/ /g' pingsOutputs/pingGoogleMod.txt
sed -i 's/:/ /g' pingsOutputs/pingGoogleMod.txt
sed -r -i 's/^/ /g' pingsOutputs/pingGoogleMod.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingGoogleMod.txt
sed -r -i 's/.//' pingsOutputs/pingGoogleMod.txt
