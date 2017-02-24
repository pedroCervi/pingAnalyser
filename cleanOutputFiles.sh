sed -i -e "1d" pingsOutputs/pingGate.txt
sed -r -i 's/..........//' pingsOutputs/pingGate.txt
sed -r -i 's/\b( 2017 64 bytes from)\b//g' pingsOutputs/pingGate.txt
sed -r -i 's/\b( 192.168.1.1)\b//g' pingsOutputs/pingGate.txt
sed -i 's/: icmp_seq=/ /g' pingsOutputs/pingGate.txt
sed -i 's/:/ /g' pingsOutputs/pingGate.txt
sed -r -i 's/\b(ttl=64 time=)\b//g' pingsOutputs/pingGate.txt
sed -r -i 's/\b( ms)\b//g' pingsOutputs/pingGate.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingGate.txt
sed -r -i 's/^.//' pingsOutputs/pingGate.txt

sed -i -e "1d" pingsOutputs/pingNeighbour.txt
sed -r -i 's/..........//' pingsOutputs/pingNeighbour.txt
sed -r -i 's/\b( 2017 64 bytes from)\b//g' pingsOutputs/pingNeighbour.txt
sed -r -i 's/\b( 179.184.126.197)\b//g' pingsOutputs/pingNeighbour.txt
sed -i 's/: icmp_seq=/ /g' pingsOutputs/pingNeighbour.txt
sed -i 's/:/ /g' pingsOutputs/pingNeighbour.txt
sed -r -i 's/\b(ttl=63 time=)\b//g' pingsOutputs/pingNeighbour.txt
sed -r -i 's/\b( ms)\b//g' pingsOutputs/pingNeighbour.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingNeighbour.txt
sed -r -i 's/^.//' pingsOutputs/pingNeighbour.txt

sed -i -e "1d" pingsOutputs/pingGoogle.txt
sed -r -i 's/..........//' pingsOutputs/pingGoogle.txt
sed -r -i 's/\b( 2017 64 bytes from)\b//g' pingsOutputs/pingGoogle.txt
sed -r -i 's/\b( 8.8.8.8)\b//g' pingsOutputs/pingGoogle.txt
sed -i 's/: icmp_seq=/ /g' pingsOutputs/pingGoogle.txt
sed -i 's/:/ /g' pingsOutputs/pingGoogle.txt
sed -r -i 's/\b(ttl=48 time=)\b//g' pingsOutputs/pingGoogle.txt
sed -r -i 's/\b( ms)\b//g' pingsOutputs/pingGoogle.txt
sed -r -i 's/ 0/ /g' pingsOutputs/pingGoogle.txt
sed -r -i 's/^.//' pingsOutputs/pingGoogle.txt

