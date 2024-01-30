#!/bin/bash

# -=-=-=-=-     CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${YELLOW}"\n\t\tTEST CREATED BY: "${DEF_COLOR};
printf ${CYAN}"GEMARTIN\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};

rm -rf traces.txt
rm -rf 0

printf "TEST 4, from Error checks\n";

./push_swap "" > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
        printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
  else
        printf "${RED}4.[KO] ${DEF_COLOR}\n";
        break
  fi
done < test_check.txt
else
        printf "${RED}4.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

printf "TEST 1, from Order nums\n";

ARG="";
N=$(./push_swap $ARG | wc -l)
if [ $N -eq 0 ]; then
        printf "${GREEN}1. [OK]${DEF_COLOR}";
else
        printf "${RED}1. [KO]${DEF_COLOR}";
fi
