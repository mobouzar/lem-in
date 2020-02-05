#!/bin/bash

echo "how to loop"
read  i

# # if [$i -gt 1]
# # then
# $a = 0
#     while [ $a -lt 10 ] 
# do 
#     # Print the values 
#     echo $a
      
#     # increment the value 
#     a=`expr $a + 1` 
# done 
#         # ./g --big-superposition >d && $(echo "---------------------" >> m) && $(./lem-in < d >r && cat r | grep L | wc -l >>m)  &&  $(./amine < d >y && cat y | grep L | wc -l >>m)
  

# # else
# #     echo -e "is NULL \n"
# # fi 
#!/bin/bash
# Basic while loop
counter=1
while [ $counter -le $i ]
do
# ./g --big-superposition >d && $(echo "---------------------" >> m) && $(./lem-in < d | grep L | wc -l >>m) && $(./nn < d | grep L | wc -l >>m) &&  $(cat d | grep 'required' | awk '{print $8}' >>m)
 ./g --big-superposition >d && $(echo "---------------------" >> m) && $(./lem-in < d >r && cat r | grep L | wc -l >>m) && $(./mm < d >ee && cat ee | grep L | wc -l >>m)   && $(cat d | grep 'required' | awk '{print $8}' >>m) && $(./mm < d >h && cat h | grep L | wc -l >>m)
((counter++))
done
echo All done
