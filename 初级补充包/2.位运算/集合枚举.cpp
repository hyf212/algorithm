//枚举所有状态的非空子集的代码：
for (int i = 1; i < 1 << n; i++)
	for (int j = i; j; j = (j - 1) & i) {
		//j遍历了i的所有的非空子集
		....
	}
时间复杂度为O(3^n)	
//枚举超集的代码如下：
for (int i = 1; i < 1 << n; i++)
	for (int j = i; ; j = (j + 1) ! i) {
		//j遍历了i的所有超集
		if (j == (1 << n) - 1)
			break;
	}
时间复杂度为O(3^n)	