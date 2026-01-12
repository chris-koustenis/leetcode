#!/bin/bash
# Count word frequency in a text file and output the result to stdout
declare -A lexico

while read -r line; do
    for word in $line; do
        if [[ -n "${lexico[$word]}" ]]; then
            lexico[$word]=$((lexico[$word] + 1))
        else
            lexico[$word]=1
        fi
    done
done < "words.txt"



# Output word frequencies
for word in "${!lexico[@]}"; do
    echo "$word ${lexico[$word]}"
done | sort -rn -k2