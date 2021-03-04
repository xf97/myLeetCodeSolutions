# Read from the file file.txt and output all valid phone numbers to stdout.
#先定义正则表达式
#对于模式1，^\((\d){3}\)(\s)(\d){3}(-)(\d){4}$
#对于模式2，^(\d){3}(-)(\d){3}-(\d){4}$
#合并一下，^(((\d){3}(-)) | (\((\d){3}\)(\s)))(\d){3}(-)(\d){4}$
#用grep
#不支持\d，用0-9表示就可以了
#time defeat: 100%
#space defeat: 77.13%
grep -P '^(([0-9]{3}(-))|(\([0-9]{3}\) ))[0-9]{3}(-)[0-9]{4}$' file.txt
