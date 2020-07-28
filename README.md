# WordSearcher
排列组合 搜索单词
```
   Usage:
   searchword <word: string> [OpenOptimization: bool] [dictionaryPath: string]
```
Example:
```
./searchword illk

读取完成!
优化后词典个数：1
读取&优化用时：0s
kill


查找用时:0s
```
如果我使用该程序并输入了任何东西作为第一个参数，程序将会返回词典中拥有的该单词排列组合成的所有单词。

第二个参数为开启优化，可用值为0或1.如果开启优化，程序将进行筛选，以提高检索速度.据我测试，在linux平台下，开启优化后查找musician这个单词，程序会在1s内给出结果，而不开启时用了整整38s.

第三个参数为词典路径，默认为当前目录下的 dic.txt 该文件格式为：空格或换行符分隔两个单词。不能有其他多余信息。
