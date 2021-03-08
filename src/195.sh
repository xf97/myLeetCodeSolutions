# Read from the file file.txt and output the tenth line to stdout.
#shell语言敲一两句命令会，敲sh脚本文件还有点懵
#$的意思是取右边的值，|的意思是把左边命令的输出作为右边命令的输入
#注意！shell语言不允许等号两边存在空格
#NR是内建变量，表示行数。$0是完整的输入记录
#time defeat: 80.89%, space defeat: 38.48%
rowNum=$(cat file.txt | wc -l)  
#-ge是大于等于 
if [ ${rowNum} -ge 10 ]; then
    awk '{if(NR==10) {print $0}}' file.txt
fi
