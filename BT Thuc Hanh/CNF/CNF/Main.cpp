#include"CNF.h"

void main()
{
	CCNF NF;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	NF.readInput();
	vector<queue<string>> suff;
	NF.Convert_prefix_to_suffixes(suff);
	NF.createTree(suff);
}