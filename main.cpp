#pragma warning (disable: 4996)
/*
2019-04-06
Lee Min Keon
Baekjoon Online Judge #1011
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <stdio.h>

int main()
{
	int testCase;
	scanf("%d", &testCase);

	for (int i_testCase = 0; i_testCase < testCase; i_testCase++)
	{
		unsigned int start, end;
		scanf("%d %d", &start, &end);

		end -= start;

		if (0 <= end && end <= 2)
		{
			printf("%d\n", end);
			continue;
		}

		int midNum = 2;
		unsigned int sum = 2;
		int count = 3;

		int even = 0;

		while (true)
		{
			sum += midNum;
			if (end <= sum)
			{
				printf("%d\n", count);
				break;
			}

			if (even % 2)
				midNum++;

			count++;
			even++;
		}
	}
}
*/
/*
2019-04-06
Lee Min Keon
Baekjoon Online Judge #10250
mkleeboy3@naver.com
*/
/*
#include <stdio.h>

int main()
{
	int testCase;
	scanf("%d", &testCase);

	while (testCase--)
	{
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);

		int h = (N % H) ? (N % H) : H;
		int w = !(N % H) ? N / H : N / H + 1;

		printf("%d\n", h * 100 + w);
	}
}
*/
/*
2019-04-06
Lee Min Keon
Baekjoon Online Judge #2775
mkleeboy3@naver.com
*/
/*
#include <stdio.h>

int arr[15][15];

int main()
{
	int testCase;
	scanf("%d", &testCase);

	for (int i = 1; i < 15; i++)
		arr[0][i] = i;

	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 15; j++)
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];

	while (testCase--)
	{
		int k, n;
		scanf("%d %d", &k, &n);

		printf("%d\n", arr[k][n]);
	}
}
*/
/*
2019-04-06
Lee Min Keon
Baekjoon Online Judge #1475
mkleeboy3@naver.com
*/
/*
#include <stdio.h>

#define MAX 10

void plusOne(char* nums, char& count)
{
	for (int i = 0; i < MAX; i++)
		nums[i]++;

	count++;
}

int main()
{
	int n;
	scanf("%d", &n);

	char count = 1;

	if (!n)
	{
		printf("%d\n", count);
		return 0;
	}

	char nums[MAX];
	for (int i = 0; i < MAX; i++)
		nums[i] = 1;

	while (n)
	{
		int singleDigit = n % 10;
		n /= 10;

		if (singleDigit == 6 || singleDigit == 9)
		{
			if (!nums[6] && !nums[9])
				plusOne(nums, count);

			(nums[6]) ? nums[6]-- : nums[9]--;
		}
		else
		{
			if (!nums[singleDigit])
				plusOne(nums, count);

			nums[singleDigit]--;
		}
	}

	printf("%d\n", count);
}
*/
/*
2019-04-07
Lee Min Keon
Baekjoon Online Judge #6064
mkleeboy3@naver.com
*/
/*
#include <stdio.h>

int main()
{
	int testCase;
	scanf("%d", &testCase);

	while (testCase--)
	{
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);

		if ((M == N) && (x != y))
		{
			printf("-1\n");
			continue;
		}

		int initialValue = (x % N) ? (x % N) : N;
		bool initialBool = false;

		for(int i=0; i < N; i++)
		{
			int calc = i * M + x;
			int mod_calc = (calc % N) ? (calc % N) : N;

			if (mod_calc == initialValue)
			{
				if (initialBool)
				{
					printf("-1\n");
					break;
				}
				initialBool = true;
			}

			if (mod_calc == y)
			{
				printf("%d\n", calc);
				break;
			}
		}
	}
}
*/
/*
2019-04-08
Lee Min Keon
Baekjoon Online Judge #10828
mkleeboy3@naver.com
*/
/*
#include <cstdio>
#include <iostream>
#include <string>

class stack
{
private:
	int m_index;
	int* m_data;
public:
	stack(int size) : m_index(-1)
	{
		m_data = new int[size];
	}

	void push(int val)
	{
		m_data[++m_index] = val;
	}

	void pop()
	{
		if (m_index == -1)
		{
			printf("%d\n", m_index);
			return;
		}

		printf("%d\n", m_data[m_index--]);
	}

	void size()
	{
		printf("%d\n", m_index + 1);
	}

	void empty()
	{
		(m_index == -1) ? printf("1\n") : printf("0\n");
	}

	void top()
	{
		(m_index == -1) ? printf("%d\n", m_index) : printf("%d\n", m_data[m_index]);
	}

	void free()
	{
		delete[] m_data;
	}
};

int main()
{
	int testCase;
	scanf("%d", &testCase);

	stack s = testCase;

	while (testCase--)
	{
		std::string line;
		std::cin >> line;

		if (!line.compare("push"))
		{
			int val;
			scanf("%d", &val);

			s.push(val);
		}
		else if (!line.compare("pop"))
		{
			s.pop();
		}
		else if (!line.compare("size"))
		{
			s.size();
		}
		else if (!line.compare("empty"))
		{
			s.empty();
		}
		else
		{
			s.top();
		}
	}

	s.free();
}
*/
/*
2019-04-08
Lee Min Keon
Baekjoon Online Judge #1874
mkleeboy3@naver.com
*/
/*
#include <cstdio>
#include <iostream>
#include <stack>

int main()
{
	std::stack<int> s;
	int n;
	scanf("%d", &n);

	char* result = new char[2*n];
	int resultIndex = 0;

	int nums = 1;
	bool flag = false;

	while (n--)
	{
		int input;
		scanf("%d", &input);

		if (s.empty())
		{
			s.push(nums++);
			result[resultIndex++] = '+';
		}

		while (s.top() < input)
		{
			s.push(nums++);
			result[resultIndex++] = '+';
		}

		if (s.top() == input)
		{
			s.pop();
			result[resultIndex++] = '-';
		}
		else
		{
			flag = true;
		}
	}

	if (flag)
	{
		puts("NO");
	}
	else
	{
		for (int i = 0; i < resultIndex; i++)
			printf("%c\n", result[i]);
	}
}
*/
/*
2019-04-08
Lee Min Keon
Baekjoon Online Judge #9012
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int testCase;
	std::cin >> testCase;

	while (testCase--)
	{
		std::stack<bool> s;

		std::string line;
		std::cin >> line;

		bool flag = false;

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '(')
				s.push(true);
			else
				if (s.empty())
				{
					flag = true;
					break;
				}
				else
				{
					s.pop();
				}
		}

		if (flag)
			std::cout << "NO\n";
		else
			if (s.empty())
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
	}
}
*/
/*
2019-04-11
Lee Min Keon
Baekjoon Online Judge #2504
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>
#include <stack>

long long int result, temp;
std::stack<bool> a; // true for (), false for []
std::stack<long long int> b; // stack for calculation
bool flag;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string line;
	std::cin >> line;

	flag = false;
	result = temp = 0;

	for (int i = 0; i < line.size(); i++)
	{
		switch (line[i])
		{
		case '(':
		{
			a.push(true);
			b.push(0);
			continue;
		}
		case '[':
		{
			a.push(false);
			b.push(0);
			continue;
		}
		case ')':
			switch (a.empty())
			{
			case true:
				flag = true;
				break;
			case false:
				switch (a.top())
				{
				case true:
				{
					a.pop();
					switch (a.empty())
					{
					case true: //if scope ends
					{
						if (!b.top()) b.top() += 1;

						result += b.top() * 2;
						b.pop();
						continue;
					}
					case false: //if scope doesn't end
					{
						temp = b.top();
						b.pop();

						switch (temp)
						{
						case 0:
							b.top() += 2;
							break;
						default:
							b.top() += temp * 2;
							break;
						}

						continue;
					}
					}
					break;
				}
				case false:
					flag = true;
					break;
				}
				break;
			}
			break;
		case ']':
			switch (a.empty())
			{
			case true:
				flag = true;
				break;
			case false:
				switch (a.top())
				{
				case true:
					flag = true;
					break;
				case false:
				{
					a.pop();
					switch (a.empty())
					{
					case true:
					{
						if (!b.top()) b.top() += 1;

						result += b.top() * 3;
						b.pop();
						continue;
					}
					case false:
					{
						temp = b.top();
						b.pop();

						switch (temp)
						{
						case 0:
							b.top() += 3;
							break;
						default:
							b.top() += temp * 3;
							break;
						}

						continue;
					}
					}
				}
				break;
				}
				break;
			}
			break;
		}
	}

	if (flag)
		std::cout << 0 << std::endl;
	else
		std::cout << result << std::endl;
}
*/
/*
2019-04-11
Lee Min Keon
Baekjoon Online Judge #10845
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>

class queue
{
private:
	int m_index;
	int* m_data;
public:
	queue(int size) : m_index(-1)
	{
		m_data = new int[size];
	}

	void push(int val)
	{
		m_data[++m_index] = val;
	}

	void pop()
	{
		if (m_index == -1)
		{
			std::cout << m_index << std::endl;
			return;
		}

		std::cout << m_data[0] << std::endl;

		for (int i = 0; i < m_index; i++)
			m_data[i] = m_data[i + 1];

		m_index--;
	}

	void size()
	{
		std::cout << m_index + 1 << std::endl;
	}

	void empty()
	{
		if (m_index == -1)
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;
	}

	void front()
	{
		if (m_index == -1)
			std::cout << m_index << std::endl;
		else
			std::cout << m_data[0] << std::endl;
	}

	void back()
	{
		if (m_index == -1)
			std::cout << m_index << std::endl;
		else
			std::cout << m_data[m_index] << std::endl;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int testCase;
	std::cin >> testCase;

	queue q(testCase);

	while (testCase--)
	{
		std::string line;
		std::cin >> line;

		if (!line.compare("push"))
		{
			int val;
			std::cin >> val;

			q.push(val);
		}
		else if (!line.compare("pop"))
			q.pop();
		else if (!line.compare("size"))
			q.size();
		else if (!line.compare("empty"))
			q.empty();
		else if (!line.compare("front"))
			q.front();
		else
			q.back();
	}
}
*/
/*
2019-04-11
Lee Min Keon
Baekjoon Online Judge #1260
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <queue>

int N, M, V;
bool** matrix;
bool* visited;
std::queue<int> q;

void dfs(int vertex)
{
	std::cout << vertex << " ";
	visited[vertex] = true;

	for (int i = 1; i < N + 1; i++)
		if (!visited[i] && matrix[vertex][i])
			dfs(i);
}

void bfs(int vertex)
{
	q.push(vertex);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		if (visited[v]) continue;

		std::cout << v << " ";
		visited[v] = true;

		for (int i = 1; i < N + 1; i++)
			if (!visited[i] && matrix[v][i])
				q.push(i);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> M >> V;

	matrix = new bool*[N + 1];
	for (int i = 1; i < N + 1; i++)
	{
		matrix[i] = new bool[N + 1];
		for (int j = 1; j < N + 1; j++)
			matrix[i][j] = false;
	}

	visited = new bool[N + 1];
	for (int i = 1; i < N + 1; i++)
		visited[i] = false;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		std::cin >> x >> y;
		matrix[x][y] = matrix[y][x] = true;
	}

	dfs(V);

	std::cout << std::endl;
	for (int i = 1; i < N + 1; i++)
		visited[i] = false;

	bfs(V);
}
*/
/*
2019-04-11
Lee Min Keon
Baekjoon Online Judge #10953
mkleeboy3@naver.com
*/
/*
#include <cstdio>

int main()
{
	int testCase;
	scanf("%d", &testCase);

	while (testCase--)
	{
		int x, y;
		scanf("%d,%d", &x, &y);
		printf("%d\n", x + y);
	}
}
*/
/*
2019-04-13
Lee Min Keon
Baekjoon Online Judge #1966
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>

#define MAX 100

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int test_case;
	std::cin >> test_case;

	char arr[MAX]; //array for sorting
	char files[MAX]; //array for weight

	while (test_case--)
	{
		int N, M;
		std::cin >> N >> M;

		for (char i = 0; i < MAX; i++)
			arr[i] = files[i] = 0;

		for (char i = 0; i < N; i++)
		{
			std::cin >> arr[i];
			files[i] = arr[i];
		}

		std::sort(arr, arr + N);

		int count = 1;
		int arr_index = N - 1;

		for (int i = 0; i < N*N; i++)
		{
			if (files[i%N] == arr[arr_index])
			{
				if (i%N == M)
				{
					std::cout << count << std::endl;
					break;
				}

				arr_index--;
				count++;
			}
		}

	}
}
*/
/*
2019-04-13
Lee Min Keon
Baekjoon Online Judge #11866
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K;
	std::cin >> N >> K;
	K--;

	bool* arr = new bool[N];
	for (int i = 0; i < N; i++)
		arr[i] = true;

	int size = N;

	std::cout << "<";

	int count = 0;
	for (int i = 0; size; i++)
	{
		if (arr[i % N])
		{
			if (count == K)
			{
				arr[i % N] = false;

				std::cout << i % N + 1;

				size--;

				if (size) std::cout << ", ";
				count = 0;
			}
			else count++;
		}
	}

	std::cout << ">" << std::endl;

	delete[] arr;
}
*/
/*
2019-04-13
Lee Min Keon
Baekjoon Online Judge #1158
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K;
	std::cin >> N >> K;
	K--;

	bool* arr = new bool[N];
	for (int i = 0; i < N; i++)
		arr[i] = true;

	int size = N;

	std::cout << "<";

	int count = 0;
	for (int i = 0; size; i++)
	{
		if (arr[i % N])
		{
			if (count == K)
			{
				arr[i % N] = false;

				std::cout << i % N + 1;

				size--;

				if (size) std::cout << ", ";
				count = 0;
			}
			else count++;
		}
	}

	std::cout << ">" << std::endl;

	delete[] arr;
}
*/
/*
2019-04-13
Lee Min Keon
Baekjoon Online Judge #10866
mkleeboy3@naver.com
*/
/*
#include <iostream>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	node* front = 0;
	node* back = 0;
	int size = 0;

	while (N--)
	{
		char line[15];
		std::cin >> line;

		switch (line[1])
		{
		case 'u': //push
		{
			int val;
			std::cin >> val;

			node* new_node = new node;
			new_node->val = val;
			new_node->right = 0;
			new_node->left = 0;
			size++;

			switch (line[5])
			{
			case 'f': //front
			{
				if (front == 0)
					back = new_node;
				else
				{
					new_node->right = front;
					front->left = new_node;
				}

				front = new_node;
			}
			break;
			case 'b': //back
			{
				if (back == 0)
					front = new_node;
				else
				{
					new_node->left = back;
					back->right = new_node;
				}

				back = new_node;
			}
			break;
			}
		}
		break;
		case 'o':
		{
			switch (line[4])
			{
			case 'f': //front
			{
				if (front == 0)
					std::cout << -1 << std::endl;
				else
				{
					std::cout << front->val << std::endl;

					node* temp = front;
					if (front == back)
					{
						front = back = 0;
					}
					else
					{
						front->right->left = 0;
						front = front->right;
					}

					size--;
					delete temp;
				}
			}
			break;
			case 'b': //back
			{
				if (back == 0)
					std::cout << -1 << std::endl;
				else
				{
					std::cout << back->val << std::endl;

					node* temp = back;
					if (back == front)
					{
						back = front = 0;
					}
					else
					{
						back->left->right = 0;
						back = back->left;
					}

					size--;
					delete temp;
				}
			}
			break;
			}
		}
		break;
		case 'i': //size
		{
			std::cout << size << std::endl;
		}
		break;
		case 'm': //empty
		{
			size ? std::cout << 0 << std::endl : std::cout << 1 << std::endl;
		}
		break;
		case 'r': //front
		{
			size ? std::cout << front->val << std::endl : std::cout << -1 << std::endl;
		}
		break;
		case 'a': //back
		{
			size ? std::cout << back->val << std::endl : std::cout << -1 << std::endl;
		}
		break;
		}
	}

}
*/
/*
2019-04-13
Lee Min Keon
Baekjoon Online Judge #1747
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>

#define MAX 1004001

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	bool nums[MAX];
	nums[0] = nums[1] = true;
	for (int i = 2; i < MAX; i++)
		nums[i] = false;

	for (int i = 2; i*i < MAX; i++)
		if (!nums[i])
			for (int j = i * i; j < MAX; j += i)
				nums[j] = true;

	int N;
	std::cin >> N;

	for (int i = N; i < MAX; i++)
	{
		if (!nums[i])
		{
			std::string string = std::to_string(i);
			int start = 0; int end = (int)string.size() - 1;

			bool flag = true;
			for (int j = 0; flag && j < string.size() / 2; j++)
				if (string[start++] != string[end--])
					flag = false;

			if (flag)
			{
				std::cout << i << std::endl;
				break;
			}
		}
	}
}
*/
/*
2019-04-13
Lee Min Keon
Baekjoon Online Judge #5597
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX_STUDENTS 30

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	bool students[MAX_STUDENTS];
	for (int i = 0; i < MAX_STUDENTS; i++)
		students[i] = false;

	for (int i = 0; i < MAX_STUDENTS-2; i++)
	{
		int student_no;
		std::cin >> student_no;

		students[student_no-1] = true;
	}

	for (int i = 0; i < MAX_STUDENTS; i++)
		if (!students[i])
			std::cout << i + 1 << std::endl;
}
*/
/*
2019-04-18
Lee Min Keon
Baekjoon Online Judge #1021
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cstdlib>

#define MAX 50

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	int target_index = 0;
	int targets[MAX];
	for (int i = 0; i < M; i++)
	{
		std::cin >> targets[i];
		targets[i]--;
	}

	int size = N;
	int count = 0;
	int i = 0;
	while (target_index < M)
	{
		int left = (i < targets[target_index]) ? abs(i + size - targets[target_index]) : abs(targets[target_index] + size - i);
		int right = abs(targets[target_index] - i);

		count += min(left, right);

		i = targets[target_index];

		//if targets[target_index] == i
		for (int j = target_index; j < M; j++)
			if (i < targets[j]) targets[j]--;

		target_index++;
		size--;
	}

	std::cout << count << std::endl;
}
*/
/*
2019-04-18
Lee Min Keon
Baekjoon Online Judge #5430
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cctype>

#define MAX 100001

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int test_case;
	std::cin >> test_case;

	char commands[MAX];
	int nums[MAX];
	char temp[4*MAX];

	while (test_case--)
	{
		int N;
		bool reverse = false;
		int nums_size = 0;
		int commands_index = 0;
		int temp_index = 0;

		//initializing arrays
		for (int i = 0; i < MAX; i++)
			commands[i] = nums[i] = 0;
		for (int i = 0; i < 4 * MAX; i++)
			temp[i] = 0;

		std::cin >> commands >> N >> temp;

		while (temp[temp_index])
		{
			int digit = 0;
			bool pass = false;
			while (isdigit(temp[temp_index]))
			{
				digit *= 10;
				digit += temp[temp_index++] - '0';
				pass = true;
			}

			if (pass) nums[nums_size++] = digit;
			temp_index++;
		}

		int size = nums_size;
		int left_end = 0;
		int right_end = nums_size - 1;

		while (commands[commands_index])
		{
			if (size < 0) break;

			switch (commands[commands_index])
			{
			case 'R':
			{
				switch (reverse)
				{
				case true:
					reverse = false;
					break;
				case false:
					reverse = true;
					break;
				}
			}
			break;
			case 'D':
			{
				switch (reverse)
				{
				case true:
					right_end--;
					break;
				case false:
					left_end++;
					break;
				}
				size--;
			}
			break;
			}

			commands_index++;
		}

		if (size < 0)
			std::cout << "error" << std::endl;
		else
			if (reverse)
			{
				std::cout << '[';
				for (int i = right_end; i >= left_end; i--)
				{
					std::cout << nums[i];
					if (i > left_end) std::cout << ',';
				}
				std::cout << ']' << std::endl;
			}
			else
			{
				std::cout << '[';
				for (int i = left_end; i <= right_end; i++)
				{
					std::cout << nums[i];
					if (i < right_end) std::cout << ',';
				}
				std::cout << ']' << std::endl;
			}
	}
}
*/
/*
2019-04-18
Lee Min Keon
Baekjoon Online Judge #11050
mkleeboy3@naver.com
*/
/*
#include <iostream>

int binomial_coefficient(int n, int k)
{
	if (!k || n == k) return 1;

	return binomial_coefficient(n - 1, k) + binomial_coefficient(n - 1, k - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K;
	std::cin >> N >> K;
	std::cout << binomial_coefficient(N, K) << std::endl;
}
*/
/*
2019-04-18
Lee Min Keon
Baekjoon Online Judge #11051
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 1001

int bi_coef[MAX][MAX];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	for (int i = 0; i < MAX; i++)
		bi_coef[i][0] = 1;

	for (int n = 1; n < MAX; n++)
		for (int k = 1; k <= n; k++)
			bi_coef[n][k] = (bi_coef[n - 1][k] + bi_coef[n - 1][k - 1]) % 10007;

	int N, K;
	std::cin >> N >> K;
	std::cout << bi_coef[N][K] << std::endl;
}
*/
/*
2019-04-18
Lee Min Keon
Baekjoon Online Judge #11401
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define PRIME 1000000007

long long int fast_pow(long long int x, long long int n)
{
	long long int result = 1;
	while (n)
	{
		if (n % 2)
		{
			result *= x;
			result %= PRIME;
		}

		x *= x;
		x %= PRIME;
		n /= 2;
	}

	return result;
}

long long int factorial(long long x)
{
	long long int result = 1;
	while (x)
	{
		result *= x;
		result %= PRIME;
		x--;
	}

	return result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long int N, K;
	std::cin >> N >> K;

	long long int A = factorial(N);
	long long int B = factorial(K) * factorial(N - K) % PRIME;

	std::cout << A * fast_pow(B, PRIME - 2) % PRIME << std::endl;
}
*/
/*
2019-04-18
Lee Min Keon
Baekjoon Online Judge #10872
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int result = 1;
	while (N)
	{
		result *= N;
		N--;
	}

	std::cout << result << std::endl;
}
*/
/*
2019-04-18
Lee Min Keon
Baekjoon Online Judge #1676
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	if (N < 5)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	int twos, fives;
	twos = fives = 0;

	while (N)
	{
		int temp = N;
		while (!(temp % 2))
		{
			twos++;
			temp /= 2;
		}

		while (!(temp % 5))
		{
			fives++;
			temp /= 5;
		}

		N--;
	}

	int result = (twos < fives) ? twos : fives;

	std::cout << result << std::endl;
}
*/
/*
2019-04-19
Lee Min Keon
Baekjoon Online Judge #2407
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX 101

class ming
{
private:
	int m_size;
	std::vector<char> m_nums;
public:
	ming() : m_size(0)
	{
		m_nums.reserve(50);
	}

	ming(char num) : m_size(1)
	{
		m_nums.push_back(num);
	}

	void print()
	{
		for (int i = m_size - 1; i >= 0; i--)
			std::cout << (int)m_nums[i];
		std::cout << std::endl;
	}

	ming operator+(const ming& other)
	{
		ming new_num;

		int this_i = 0;
		int other_i = 0;

		while (this_i < this->m_size && other_i < other.m_size)
		{
			new_num.m_nums.push_back(this->m_nums[this_i++] + other.m_nums[other_i++]);
			new_num.m_size++;
		}

		while (this_i < this->m_size)
		{
			new_num.m_nums.push_back(this->m_nums[this_i++]);
			new_num.m_size++;
		}

		while (other_i < other.m_size)
		{
			new_num.m_nums.push_back(other.m_nums[other_i++]);
			new_num.m_size++;
		}

		for (int i = 0; i < new_num.m_size; i++)
		{
			if (new_num.m_nums[i] > 9)
			{
				new_num.m_nums[i] %= 10;
				if (i + 1 < new_num.m_size)
				{
					new_num.m_nums[i + 1] += 1;
				}
				else
				{
					new_num.m_nums.push_back(1);
					new_num.m_size++;
				}
			}
		}

		return new_num;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	ming bi_coef[MAX][MAX];

	for (int i = 0; i < MAX; i++)
		bi_coef[i][0] = 1;

	for (int n = 1; n < MAX; n++)
		for (int k = 1; k <= n; k++)
			bi_coef[n][k] = bi_coef[n - 1][k] + bi_coef[n - 1][k - 1];

	int N, K;
	std::cin >> N >> K;

	bi_coef[N][K].print();
}
*/
/*
2019-04-19
Lee Min Keon
Baekjoon Online Judge #2407
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <tgmath.h>

#define MAX 50

int calc(int N, int M)
{
	if (M == 0) return 1;
	else if (N == M) return 1;
	else
	{
		int shorter = (N - M < M) ? N - M : M;

		double result = 1;
		while(shorter)
		{
			result = result * (double)N / shorter;
			shorter--;
			N--;
		}

		return round(result);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	while (true)
	{
		int N, M;
		std::cin >> N >> M;

		if (N == 0 && N == M) break;

		std::cout << calc(N, M) << std::endl;
	}
}
*/
/*
2019-04-21
Lee Min Keon
Baekjoon Online Judge #9375
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>

#define MAX 30

struct pair
{
	std::string str;
	int count;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int test_case;
	std::cin >> test_case;

	pair arr[MAX];

	while (test_case--)
	{
		int arr_index = 0;

		for (int i = 0; i < MAX; i++)
		{
			arr[i].str = std::string();
			arr[i].count = 0;
		}

		int input;
		std::cin >> input;

		for (int i = 0; i < input; i++)
		{
			std::string dummy, category;
			std::cin >> dummy >> category;

			bool exist = false;
			for (int j = 0; j < arr_index; j++)
				if (!arr[j].str.compare(category))
				{
					arr[j].count++;
					exist = true;
				}

			if (!exist)
			{
				arr[arr_index].str = category;
				arr[arr_index++].count++;
			}
		}

		int result = 1;
		for (int i = 0; i < arr_index; i++)
			result *= (arr[i].count + 1);

		std::cout << result - 1 << std::endl;
	}
}
*/
/*
2019-04-21
Lee Min Keon
Baekjoon Online Judge #2490
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string ref = "DCBAE";

	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		for (int j = 0; j < 4; j++)
		{
			int temp;
			std::cin >> temp;
			if (temp) count++;
		}
		std::cout << ref[count] << std::endl;
	}
}
*/
/*
2019-04-21
Lee Min Keon
Baekjoon Online Judge #1022
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cstdlib>
#include <cmath>

int find_max(int a, int b) //finds maximum
{
  	return a > b ? a : b;
}

int num_digit(int a)
{
	int digit = 1;

	while(a > 9)
	{
		digit++;
		a /= 10;
	}

	return digit;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
  	std::cin.tie(NULL);

  	int r1, r2, c1, c2;
	std::cin >> r1 >> c1 >> r2 >> c2;

	int ver = r2 - r1 + 1; //new array size
	int hor = c2 - c1 + 1; //new array size

	int** arr = new int*[ver]; //allocating process
	int** digits = new int*[ver];
	for(int i=0; i<ver; i++)
    {
		arr[i] = new int[hor];
		digits[i] = new int[hor];
      	for(int j=0; j<hor; j++)
      	{
          	arr[i][j] = 0;
          	digits[i][j] = 0;
      	}
    }

	int x, y, count, side, max_digit;
	x = y = 0;
  	count = 1;
  	side = 2;
  	max_digit = -1;

  	if(0 <= y - r1 && y - r1 < ver && 0 <= x - c1 && x - c1 < hor)
  	{
		int temp = num_digit(count);

      	arr[y - r1][x - c1] = count;
      	digits[y - r1][x - c1] = temp;

      	if(temp > max_digit) max_digit = temp;
  	}

    count++;
  	x++;

  	int max = -1;
    max = find_max(max, abs(r1));
  	max = find_max(max, abs(r2));
  	max = find_max(max, abs(c1));
  	max = find_max(max, abs(c2));

  	max *= 2;
  	max += 1;
    while(side < max)
    {
    	//위로
      	for(int i=1; i<=side; i++)
        {
			if(0 <= y - r1 && y - r1 < ver && 0 <= x - c1 && x - c1 < hor)
			{
      			int temp = num_digit(count);

		      	arr[y - r1][x - c1] = count;
		      	digits[y - r1][x - c1] = temp;

		      	if(temp > max_digit) max_digit = temp;
			}

          	if(i != side)
          	{
          		y--;
          		count++;
          	}
        }

      	//왼쪽
      	for(int i=1; i<=side; i++)
        {
			if(0 <= y - r1 && y - r1 < ver && 0 <= x - c1 && x - c1 < hor)
			{
      			int temp = num_digit(count);
		      	arr[y - r1][x - c1] = count;
		      	digits[y - r1][x - c1] = temp;

		      	if(temp > max_digit) max_digit = temp;
			}

          	if(i != side)
          	{
          		x--;
          		count++;
          	}
        }

      	side++;
      	x--;
      	count++;

      	//아래
      	for(int i=1; i<=side; i++)
        {
			if(0 <= y - r1 && y - r1 < ver && 0 <= x - c1 && x - c1 < hor)
			{
      			int temp = num_digit(count);

		      	arr[y - r1][x - c1] = count;
		      	digits[y - r1][x - c1] = temp;

		      	if(temp > max_digit) max_digit = temp;
			}

          	if(i != side)
          	{
          		y++;
          		count++;
          	}
        }

      	//오른쪽
      	for(int i=1; i<=side; i++)
        {
			if(0 <= y - r1 && y - r1 < ver && 0 <= x - c1 && x - c1 < hor)
			{
      			int temp = num_digit(count);

		      	arr[y - r1][x - c1] = count;
		      	digits[y - r1][x - c1] = temp;

		      	if(temp > max_digit) max_digit = temp;
			}

          	if(i != side)
          	{
          		x++;
          		count++;
          	}
        }

      	side++;
      	x++;
      	count++;
    }

	for(int i=0; i<ver; i++)
    {
      	for(int j=0; j<hor; j++)
      	{
      		for(int k=0; k<max_digit - digits[i][j]; k++)
      			std::cout << ' ';
      		std::cout << arr[i][j] << ' ';
      	}
  		std::cout << std::endl;
    }

    for(int i=0; i<ver; i++)
    {
    	delete[] arr[i];
    	delete[] digits[i];
    }
    delete[] arr;
    delete[] digits;
}
*/
/*
2019-05-02
Lee Min Keon
Baekjoon Online Judge #3053
mkleeboy3@naver.com
*/
/*
#include <cstdio>
#include <cmath>

#define _USE_MATH_DEFINES

int main()
{
	int R;
	scanf("%d", &R);

	double E_RESULT = M_PI * R * R;
	double T_RESULT = 2 * R * R;

	printf("%f\n%f\n", E_RESULT, T_RESULT);
}
*/
/*
2019-05-02
Lee Min Keon
Baekjoon Online Judge #1850
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define ll long long

ll find_gcd(ll A, ll B)
{
	ll gcd = A % B;

	while(gcd)
	{
		A = B;
		B = gcd;
		gcd = A % B;
	}

	return B;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	ll A, B;
	std::cin >> A >> B;

	ll rep = find_gcd(A, B);

	for(ll i=0; i<rep; i++)
		std::cout << 1;
	std::cout << std::endl;
}
*/
/*
2019-05-02
Lee Min Keon
Baekjoon Online Judge #2981
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int arr[100];
	int arr_index = 0;

	int arr_limit;
	std::cin >> arr_limit;

	int min = 1000000001;
	int rem;

	for(int i=0; i<arr_limit; i++, arr_index++)
	{
		std::cin >> arr[arr_index];
		if(min > arr[arr_index])
			min = arr[arr_index];
	}
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #10171
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cout << "\\    /\\\n )  ( ')\n(  /  )\n \\(__)|\n";
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #2588
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int a, b;
	std::cin >> a >> b;
	int temp = b;

	while(temp)
	{
		std::cout << a * (temp % 10) << '\n';

		temp /= 10;
	}

	std::cout << a * b << '\n';
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #1330
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, B;
	std::cin >> A >> B;

	A > B ? std::cout << '>' : A == B ? std::cout << "==" : std::cout << '<';
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #2753
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	bool flag = 0;
	int input;
	std::cin >> input;

	if(!(input % 4))
	{
		flag = 1;
		if(!(input % 100))
		{
			flag = 0;
			if(!(input % 400))
				flag = 1;
		}
	}

	std::cout << flag;
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #2884
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int H, M;
	std::cin >> H >> M;
	M -= 45;

	if(M < 0)
	{
		H--;
		M += 60;
		if(H < 0) H += 24;
	}

	std::cout << H << ' ' << M << '\n';
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #10818
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX_ABS 1000001

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int max = -1 * MAX_ABS;
	int min = MAX_ABS;

	int input;
	while(N--)
	{
		std::cin >> input;
		if(input > max) max = input;
		if(input < min) min = input;
	}

	std::cout << min << ' ' << max << std::endl;
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #2562
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 1;
	int max = -1;
	int max_count;

	int input;
	while(n < 10)
	{
		std::cin >> input;

		if(input > max)
		{
			max = input;
			max_count = n;
		}

		n++;
	}

	std::cout << max << std::endl << max_count << std::endl;
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #3052
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 42

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int arr[MAX];
	for(int i=0; i<MAX; i++)
		arr[i] = 0;

	int input;
	for(int i=0; i<10; i++)
	{
		std::cin >> input;
		arr[input%42]++;
	}

	int count = 0;
	for(int i=0; i<MAX; i++)
		if(arr[i]) count++;

	std::cout << count << std::endl;
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #15596
mkleeboy3@naver.com
*/
/*
#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    std::vector<int>::iterator itr;

	for(itr = a.begin(); itr < a.end(); itr++)
		ans += *itr;

	return ans;
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #2447
mkleeboy3@naver.com
*/
/*
#include <iostream>

void copy(char** arr, int src, int dest_i, int dest_j)
{
	for(int i=0; i<src; i++, dest_i++)
	{
		int temp_j = dest_j;
		for(int j=0; j<src; j++, temp_j++)
			arr[dest_i][temp_j] = arr[i][j];
	}
}

void recursion(char** arr, int N, int count)
{
	if(count >= N) return;

	copy(arr, count, 0, count);
	copy(arr, count, 0, count*2);
	copy(arr, count, count, 0);
	copy(arr, count, count, count*2);
	copy(arr, count, count*2, 0);
	copy(arr, count, count*2, count);
	copy(arr, count, count*2, count*2);

	recursion(arr, N, count*3);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	char** arr = new char*[N];
	for(int i=0; i<N; i++)
	{
		arr[i] = new char[N];
		for(int j=0; j<N; j++)
			arr[i][j] = 0;
	}

	arr[0][0] = '*';

	recursion(arr, N, 1);

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			arr[i][j] == '*' ? std::cout << arr[i][j] : std::cout << ' ';
		std::cout << '\n';
	}
}
*/
/*
2019-08-31
Lee Min Keon
Baekjoon Online Judge #2447
mkleeboy3@naver.com
*/
/*
#include <iostream>

void recursion(char** arr, int N, int i, int j)
{
	if(N < 1) return;

	arr[i][j] = '*';

	recursion(arr, N/3, i, j);
	recursion(arr, N/3, i, j + N/3);
	recursion(arr, N/3, i, j + N/3*2);
	recursion(arr, N/3, i + N/3, j);
	recursion(arr, N/3, i + N/3, j + N/3*2);
	recursion(arr, N/3, i + N/3*2, j);
	recursion(arr, N/3, i + N/3*2, j + N/3);
	recursion(arr, N/3, i + N/3*2, j + N/3*2);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	char** arr = new char*[N];
	for(int i=0; i<N; i++)
	{
		arr[i] = new char[N];
		for(int j=0; j<N; j++)
			arr[i][j] = 0;
	}

	recursion(arr, N, 0, 0);

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			arr[i][j] == '*' ? std::cout << arr[i][j] : std::cout << ' ';
		std::cout << '\n';
	}
}
*/
/*
2019-09-01
Lee Min Keon
Baekjoon Online Judge #11729
mkleeboy3@naver.com
*/
/*
#include <iostream>

void hanoi(int size, int src, int dest)
{
	if(size == 1)
	{
		std::cout << src << ' ' << dest << '\n';
		return;
	}

	int aux = 6 - src - dest;

	hanoi(size - 1, src, aux);
	std::cout << src << ' ' << dest << '\n';
	hanoi(size - 1, aux, dest);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int count = 0;
	for(int i=0; i<N; i++)
		count = count*2 + 1;

	std::cout << count << std::endl;

	hanoi(N, 1, 3);
}
*/
/*
2019-09-01
Lee Min Keon
Baekjoon Online Judge #1712
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, B, C;
	std::cin >> A >> B >> C;

	if(B >= C)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	double result = A / (C-B);
	if (result == floor(A / (C-B)))
		std::cout << (int)result + 1 << std::endl;
	else
		std::cout << (int)ceil(result) << std::endl;
}
*/
/*
2019-09-01
Lee Min Keon
Baekjoon Online Judge #2869
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, B, V;
	std::cin >> A >> B >> V;

	int objective = V - A;
	int progress = A - B;B

	std::cout << (int)ceil((double)objective / progress) + 1 << std::endl;
}
*/
/*
2019-09-01
Lee Min Keon
Baekjoon Online Judge #1085
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, B, V;
	std::cin >> A >> B >> V;

	int objective = V - A;
	int progress = A - B;

	std::cout << (int)ceil((double)objective / progress) + 1 << std::endl;
}
*/
/*
2020-02-07
Lee Min Keon
Baekjoon Online Judge #17136
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX_SIZE 10
#define SQUARES 5
#define MAX_VALUE 26

bool grid[MAX_SIZE][MAX_SIZE]; // a 2 dimensional array containing information of where we could fit squares
int result = MAX_VALUE, max_count = 0; // result: the global final minimum value containing the overall result, max_count: the max life span of our recursion
bool flag = false; // true: grid is filled with 0s from the beginning, false: the grid has at least one 1s

void fill_square(int a, int b, int size, int value) // at given coordinate (a, b), start filling a (size * size) sized square with value (value)
{
    for(int i=a; i<a+size && i<MAX_SIZE; i++)
        for(int j=b; j<b+size && j<MAX_SIZE; j++)
            grid[i][j] = value;
}

bool fit_square(char* sq_count, int a, int b, int size) // at given coordinate (a, b), determine whether a (size * size) sized square fits
{
    int count = 0;
    for(int i=a; i<a+size && i<MAX_SIZE; i++) // iterate over the grid and count
        for(int j=b; j<b+size && j<MAX_SIZE; j++)
            if(grid[i][j]) count++;

    if(count == size*size) // if the square fits
    {
        if(!sq_count[size-1]) return false; // the square fits, but lacks amount, so return false

        sq_count[size-1]--; // since we fitted one square, decrement the number of the fitted square
        fill_square(a, b, size, 0); // since we fitted one square, fill the grid with 0s
        return true; // our square has fitted perfectly, so return true
    }

    return false; // if the square doesn't fit, return false (default return value)
}

void scan(char* prev_squares, int total, int count) // prev_squares: array containing the number of squares left on the previous iteration, total: local result, count: life
{
    if(count == max_count) // if our recursion life span is done
    {
        if(result > total) // compare the local result (total) with global result (result) and adjust it if necessary
            result = total;

        return;
    }

    for(int ver=0; ver<MAX_SIZE; ver++) // iterations for finding 1 in the grid
        for(int hor=0; hor<MAX_SIZE; hor++)
            if(grid[ver][hor]) // when found 1 inside the grid
            {
                char sq_count[SQUARES]; // copy of prev_squares for new junctions (new recursions) for the sake of preserving the original number of squares left
                for(int i=0; i<SQUARES; i++) // copy the array
                    sq_count[i] = prev_squares[i];

                for(int i=5; i>0; i--) // try all square sizes starting from 5 (5 ~ 1)
                    if(fit_square(sq_count, ver, hor, i)) // if the square fits on the selected coordinate (grid updated to 0)
                    {
                        flag = true; // the grid has at least one 1s, so flag = true
                        scan(sq_count, total+1, count+(i*i)); // start a new junction by calling a recursive function
                        fill_square(ver, hor, i, 1); // restore the grid back to 1s
                        for(int j=0; j<SQUARES; j++)
                            sq_count[j] = prev_squares[j]; // restore the number of squares left
                    }

                return; // we repeat this recursively for only one coordinate at a time (one coordinate for one recursive scope)
            }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i=0; i<MAX_SIZE; i++)
        for(int j=0; j<MAX_SIZE; j++)
        {
            std::cin >> grid[i][j];
            if(grid[i][j])
                max_count++; // the life span of our recursive function is the number of 1s inside the grid
        }

    char sq_count[SQUARES];
    for(int i=0; i<SQUARES; i++) // initialize the number of squares left with 5s, respectively
        sq_count[i] = 5;

    scan(sq_count, 0, 0); // start from coordinate (0, 0)

    result = (flag && result == MAX_VALUE) ? -1 : (!flag && result == MAX_VALUE) ? 0 : result;
    std::cout << result << std::endl;

    return 0;
}
*/
/*
2020-02-07
Lee Min Keon
SW Expert Academy #1954
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX_N 10

int N;
int SNAIL[MAX_N][MAX_N];

void swirl(int a, int b, int num, int life) // a is vertical, b is horizontal
{
    if(life == N*N)
        return;

    SNAIL[a][b] = num;

    if(b < N-1 && !SNAIL[a][b+1]) swirl(a, b+1, num+1, life+1);
    if(a < N-1 && !SNAIL[a+1][b]) swirl(a+1, b, num+1, life+1);
    if(0 < b && !SNAIL[a][b-1]) swirl(a, b-1, num+1, life+1);
    if(0 < a && !SNAIL[a-1][b]) swirl(a-1, b, num+1, life+1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int TC;
    std::cin >> TC;

    for(int tc = 0; tc < TC; tc++)
    {
        for(int i=0; i<MAX_N; i++)
            for(int j=0; j<MAX_N; j++)
                SNAIL[i][j] = 0;

        std::cout << '#' << tc+1 << '\n';

        std::cin >> N;

        swirl(0, 0, 1, 0);

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                std::cout << SNAIL[i][j] << ' ';
            std::cout << std::endl;
        }
    }

    return 0;
}
*/
/*
2020-02-07
Lee Min Keon
Baekjoon Online Judge #17135
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 15

int N, M, D, base;
int grid[2][MAX][MAX];

void search_enemy(int ver, int hor, int life, int range, int& flag)
{
    if(flag || !life)
        return;

    if(ver < 0 || hor < 0)
    {
        if(life > range)
            search_enemy(ver-1, hor+1, life-1, range, flag);
        else
            search_enemy(ver+1, hor+1, life-1, range, flag);

        return;
    }

    if(grid[1][ver][hor] == 1) // the first kill
    {
        grid[1][ver][hor] = -1;
        flag = 1;
        return;
    }
    else if(grid[1][ver][hor] == -1) // killed simultaneously
    {
        flag = -1;
        return;
    }

    if(life > range)
        search_enemy(ver-1, hor+1, life-1, range, flag);
    else
        search_enemy(ver+1, hor+1, life-1, range, flag);
}

int attack(int src) // src is on the horizontal axis
{
    int flag = 0; // 1 if found & killed, 0 if not found, -1 if killed simultaneously

    for(int i=1; i<=D; i++)
    {
        search_enemy(base-1, src-i+1, i*2-1, i, flag);
        if(flag) return flag;
    }

    return flag;
}

int commence(int a, int b, int c, int total) // [base][a, b, c]
{
    for(int i=0; i<N; i++)
    {
        if(attack(a) == 1) total++;
        if(attack(b) == 1) total++;
        if(attack(c) == 1) total++;

        base--;

        for(int j=base-1; j>=0; j--)
            for(int k=0; k<M; k++)
                if(grid[1][j][k] == -1)
                    grid[1][j][k] = 0;
    }

    return total;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M >> D;

    for(int k=0; k<2; k++)
        for(int i=0; i<MAX; i++)
            for(int j=0; j<MAX; j++)
                grid[k][i][j] = 0;

    int max = 0;
    int result;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            std::cin >> grid[0][i][j];

    for(int i=0; i<M-2; i++)
        for(int j=i+1; j<M-1; j++)
            for(int k=j+1; k<M; k++)
            {
                base = N;
                for(int l=0; l<N; l++)
                    for(int m=0; m<M; m++)
                        grid[1][l][m] = grid[0][l][m];

                result = commence(i, j, k, 0);
                if(result > max)
                    max = result;
            }

    std::cout << max << std::endl;

    return 0;
}
*/
/*
2020-02-08
Lee Min Keon
SW Expert Academy #4615
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX_N 8

int N, M, B, W, grid[MAX_N][MAX_N]; // B = 1, W = 2

void proceed(int ver, int hor, int changer, int type, int& flag)
{
    if(flag || ver < 0 || hor < 0 || ver > N-1 || hor > N-1 || !grid[ver][hor])
        return;
    
    if(grid[ver][hor] == changer)
    {
        flag = true;
        return;
    }
    
    switch(type)
    {
        case 0:
            proceed(ver, hor-1, changer, 0, flag);
            break;
        case 1:
            proceed(ver-1, hor-1, changer, 1, flag);
            break;
        case 2:
            proceed(ver-1, hor, changer, 2, flag);
            break;
        case 3:
            proceed(ver-1, hor+1, changer, 3, flag);
            break;
        case 4:
            proceed(ver, hor+1, changer, 4, flag);
            break;
        case 5:
            proceed(ver+1, hor+1, changer, 5, flag);
            break;
        case 6:
            proceed(ver+1, hor, changer, 6, flag);
            break;
        case 7:
            proceed(ver+1, hor-1, changer, 7, flag);
            break;
    }
    
    if(flag)
        grid[ver][hor] = changer;
}

void print_grid()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            if(grid[i][j] == 1)
                std::cout << "B ";
            else if(grid[i][j] == 2)
                std::cout << "W ";
            else
                std::cout << "  ";
        std::cout << "\n";
        std::cout << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int TC;
    std::cin >> TC;
    
    for(int tc=0; tc<TC; tc++)
    {
        B = W = 0;
        
        for(int i=0; i<MAX_N; i++)
            for(int j=0; j<MAX_N; j++)
                grid[i][j] = 0;
        
        std::cin >> N >> M;
        
        for(int i=N/2-1; i<N/2+1; i++)
            for(int j=N/2-1; j<N/2+1; j++)
                if(i == j)
                    grid[i][j] = 2; // assign W
                else
                    grid[i][j] = 1; // assign B
        
        //print_grid();
        
        int s, e, c;
        for(int m=0; m<M; m++)
        {
            std::cin >> s >> e >> c;
            
            for(int i=0; i<8; i++)
            {
                int flag = 0;
                grid[e-1][s-1] = -1;
                proceed(e-1, s-1, c, i, flag);
            }
            
            grid[e-1][s-1] = c;
            
            //print_grid();
        }
        
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(grid[i][j] == 1) B++;
                else if(grid[i][j] == 2) W++;
        
        std::cout << '#' << tc+1 << ' ' << B << ' ' << W << '\n';
    }
    
    return 0;
}
*/
/*
2020-02-08
Lee Min Keon
SW Expert Academy #1240
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>

#define MAX_N 50
#define MAX_M 100
#define MAX_WORD 8
#define CODE_SIZE 56

int find_code(std::string* decrypt, std::string& temp)
{
    int num = -1;
    for(int i=0; i<10; i++)
        if(decrypt[i] == temp)
        {
            num = i;
            break;
        }
    
    return num;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int TC;
    std::cin >> TC;
    
    std::string decrypt[10];
    decrypt[0] = "3211";
    decrypt[1] = "2221";
    decrypt[2] = "2122";
    decrypt[3] = "1411";
    decrypt[4] = "1132";
    decrypt[5] = "1231";
    decrypt[6] = "1114";
    decrypt[7] = "1312";
    decrypt[8] = "1213";
    decrypt[9] = "3112";
    
    for(int tc=0; tc<TC; tc++)
    {
        int result, codeword_i, N, M, codeword[MAX_WORD];
        bool arr[CODE_SIZE];
        
        result = codeword_i = 0;
        
        std::cin >> N >> M;
        
        bool found = 0;
        bool search = 1;
        
        for(int i=0; i<N; i++)
        {
            std::string input = "";
            std::cin >> input;
            
            if(search)
                for(int j=0; j<M; j++)
                    if(input[j] == '1')
                    {
                        search = 0;
                        found = 1;
                        break;
                    }
            
            if(found)
            {
                int end;
                for(int j=M-1; j>=0; j--)
                    if(input[j] == '1')
                    {
                        end = j;
                        break;
                    }
                
                for(int j=CODE_SIZE-1; j>=0; j--, end--)
                    if(input[end] == '1')
                        arr[j] = 1;
                    else
                        arr[j] = 0;
                found = 0;
            }
        }
        
        bool start = arr[0];
        char divider = 1;
        std::string temp = "";
        for(int j=0; j<CODE_SIZE-1; j++, divider++)
        {
            if(start != arr[j+1])
            {
                temp.push_back(divider + '0');
                
                start = start ? 0 : 1;
                divider = 0;
            }
            
            if(!((j+1) % 7))
            {
                codeword[codeword_i++] = find_code(decrypt, temp);
                
                start = arr[j+1];
                divider = 0;
                temp = "";
            }
        }
        
        temp.push_back(divider + '0');
        codeword[codeword_i++] = find_code(decrypt, temp);
        
        bool error = 0;
        for(int i=0; i<MAX_WORD; i++)
            if(codeword[i] == -1)
            {
                printf("#%d %d\n", tc+1, 0);
                error = 1;
                break;
            }
        
        if(error) continue;
        
        int even, odd;
        even = odd = 0;
        
        for(int i=0; i<MAX_WORD-1; i++)
            if(i % 2)
                odd += codeword[i];
            else
                even += 3 * codeword[i];
        
        if(!((odd + even + codeword[7]) % 10))
            for(int i=0; i<MAX_WORD; i++)
                result += codeword[i];
        
        printf("#%d %d\n", tc+1, result);
    }
    
    return 0;
}
*/
/*
2020-02-10
Lee Min Keon
Baekjoon Online Judge #1002
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cmath>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int TC;
    std::cin >> TC;
    
    while(TC--)
    {
        double x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        double dis = sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
        
        //std::cout << dis << ' ';
        
        int result = 0;
        
        if(dis > r1+r2)
            result = 0;
        else if(dis == r1+r2)
            result = 1;
        else if(dis > abs(r1-r2))
            result = 2;
        else if(dis == abs(r1-r2))
            if(r1 == r2)
                result = -1;
            else
                result = 1;
            else if(dis > 0)
                result = 0;
            else // dis == 0
                if(r1 == r2) result = -1;
        
        std::cout << result << '\n';
    }
    
    return 0;
}
*/
/*
2020-02-10
Lee Min Keon
Baekjoon Online Judge #2522
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cmath>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    
    for(int i=1; i<=N; i++)
    {
        for(int j=N-i; j>0; j--)
            std::cout << ' ';
        for(int j=0; j<i; j++)
            std::cout << '*';
        
        std::cout << '\n';
    }
    
    for(int i=1; i<N; i++)
    {
        
        for(int j=0; j<i; j++)
            std::cout << ' ';
        for(int j=N-i; j>0; j--)
            std::cout << '*';
        
        std::cout << '\n';
    }
    
    return 0;
}
*/
/*
2020-02-10
Lee Min Keon
Baekjoon Online Judge #2522
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cmath>

void print(int N, int life)
{
    for(int i=0; i<N; i++, life--)
        if(life > N)
            std::cout << ' ';
        else
            std::cout << '*';
    
    std::cout << '\n';
}

void search(int N, int life)
{
    print(N, life);
    
    if(life == N) return;
    search(N, life-1);
    
    print(N, life);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    
    search(N, 2*N-1);
    
    return 0;
}
*/
/*
2020-02-10
Lee Min Keon
Baekjoon Online Judge #2523
mkleeboy3@naver.com
*/
/*
#include <iostream>

void print(int& N, int life)
{
    for(int i=0; i<N; i++, life++)
        if(2*N-1 >= life)
            std::cout << '*';
    
    std::cout << '\n';
}

void search(int& N, int life)
{
    print(N, life);
    
    if(life == N) return;
    search(N, life-1);
    
    print(N, life);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    
    search(N, 2*N-1);
    
    return 0;
}
*/
/*
2020-02-10
Lee Min Keon
Baekjoon Online Judge #1197 Linked List & Kruskal Implementation
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_VERTICES 10001
#define MAX_EDGES 100001

typedef struct AD_List
{
	int vertex;
	int edge;
	struct AD_List* next;
} AD_List;

typedef struct pairs
{
	int ver1;
	int ver2;
	int edge;
} pairs;

AD_List MST[MAX_VERTICES];
char visited[MAX_VERTICES]; // 0: popped, 1: visited & in stack, 2: visited & not in stack
std::vector<pairs> edges;

void find_cycle(std::vector<int>& stack, bool& is_cycle, int& V, int index, int parent)
{
    visited[index] = 1;
    stack.push_back(index);
    
    for(AD_List* search = MST[index].next; search && !is_cycle; search = search->next)
        if(!visited[search->vertex])
            find_cycle(stack, is_cycle, V, search->vertex, index);
        else if(visited[search->vertex] == 1 && search->vertex != parent) // if vertex is visited & in stack
        {
            is_cycle = true;
            return;
        }
    
    if(is_cycle) return;
    
    stack.pop_back();
    visited[index] = 2;
}

bool compare(pairs A, pairs B)
{
	if (A.edge == B.edge)
		return A.ver1 < B.ver1;
	else
		return A.edge < B.edge;
}

void list_print(AD_List* list, int N)
{
    for(int i = 1; i <= N; i++)
    {
        std::cout << "List " << i << ": ";
        for(AD_List* search = list[i].next; search; search = search->next)
            std::cout << search->vertex << ' ';
        std::cout << '\n';
    }
}

void list_add(AD_List* list, int src, int dest, int weight)
{
	AD_List* new_node = new AD_List;
	new_node->vertex = dest;
	new_node->edge = weight;
	new_node->next = NULL;

	if (!list[src].next)
	{
		list[src].next = new_node;
	}
	else
	{
		new_node->next = list[src].next;
		list[src].next = new_node;
	}
}

void list_del(AD_List* list, int src, int dest)
{
    AD_List* prev = &list[src];
    
    for(AD_List* search = list[src].next; search; search = search->next)
    {
        if(search->vertex == dest)
        {
            AD_List* del_node = search;
            prev->next = search->next;
            delete del_node;
            
            return;
        }
        prev = search;
    }
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int V, E, result; result = 0;
	std::cin >> V >> E;

	for (int i = 0; i < MAX_VERTICES; i++)
	{
        MST[i].vertex = 0;
		MST[i].edge = 0;
		MST[i].next = NULL;
        
        visited[i] = false;
	}

	int src, dest, weight;
	pairs temp;

	for (int i = 0; i < E; i++)
	{
		std::cin >> src >> dest >> weight;
		temp.ver1 = src;
		temp.ver2 = dest;
		temp.edge = weight;
		edges.push_back(temp);
	}
    
	//sort edges in ascending order
	std::sort(edges.begin(), edges.end(), compare);
    
	//kruskal's algorithm
	for (int i = 0; i < E; i++)
	{
        for(int j = 1; j <= V; j++)
            visited[j] = 0;
        
        std::vector<int> stack;
        bool is_cycle = false;
        pairs start = edges.front();
        
        list_add(MST, start.ver1, start.ver2, start.edge);
        list_add(MST, start.ver2, start.ver1, start.edge);
        
        find_cycle(stack, is_cycle, V, start.ver1, 0);
        
        if(is_cycle)
        {
            list_del(MST, start.ver1, start.ver2);
            list_del(MST, start.ver2, start.ver1);
        }
        else
            result += start.edge;
        
        edges.erase(edges.begin());
	}
    
    std::cout << result << std::endl;

    return 0;
}
*/
/*
2020-02-11
Lee Min Keon
Baekjoon Online Judge #1197 Union Find & Kruskal Implementation
mkleeboy3@naver.com
*/
//https://www.acmicpc.net/problem/1626
//https://cp-algorithms.com/graph/second_best_mst.html
//https://cp-algorithms.com/graph/lca_binary_lifting.html
//https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
/*
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_VERTICES 10001
#define MAX_EDGES 100001

int UF[MAX_VERTICES], UF_SIZE[MAX_VERTICES];

typedef struct pairs
{
    int ver1;
    int ver2;
    int edge;
} pairs;

void unite(int A, int B, int& V)
{
    int smaller = (UF_SIZE[UF[A]] < UF_SIZE[UF[B]]) ? UF[A] : UF[B];
    int larger = (UF_SIZE[UF[A]] < UF_SIZE[UF[B]]) ? UF[B] : UF[A];
    
    for(int i=1; i<=V; i++)
        if(UF[i] == smaller)
            UF[i] = larger;
    
    UF_SIZE[larger] += UF_SIZE[smaller];
    UF_SIZE[smaller] = 0;
}

bool find(int A, int B) // if A & B connected returns true, else return false
{
    if(UF[A] == UF[B])
        return true;
    
    return false;
}

bool compare(pairs A, pairs B)
{
    if (A.edge == B.edge)
        return A.ver1 < B.ver1;
    else
        return A.edge < B.edge;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<pairs> edges;
    int V, E, result; result = 0;
    std::cin >> V >> E;
    
    for(int i=0; i<MAX_VERTICES; i++)
    {
        UF[i] = i;
        UF_SIZE[i] = 0;
    }
    
    for(int i=0; i<E; i++)
    {
        pairs temp;
        std::cin >> temp.ver1 >> temp.ver2 >> temp.edge;
        edges.push_back(temp);
    }
    
    std::sort(edges.begin(), edges.end(), compare);
    
    for(std::vector<pairs>::iterator p = edges.begin(); p != edges.end(); p++)
        if(!find(p->ver1, p->ver2))
        {
            unite(p->ver1, p->ver2, V);
            result += p->edge;
        }
    
    std::cout << result << '\n';
    
    return 0;
}
*/
/*
2020-02-11
Lee Min Keon
Baekjoon Online Judge #1626 Union Find & Kruskal Implementation
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

#define MAX_VERTICES 10001
#define MAX_EDGES 100001

typedef struct pairs
{
    int a;
    int b;
    int edge;
    bool inMST;
} pairs;

int UF[MAX_VERTICES], UF_SIZE[MAX_VERTICES]; // disjoint set for MST cycle check
std::vector<std::vector<std::pair<int, int>>> MST(MAX_VERTICES); // adj list for MST

int unite(int A, int B, int& V)
{
    int smaller = (UF_SIZE[UF[A]] < UF_SIZE[UF[B]]) ? UF[A] : UF[B];
    int larger = (UF_SIZE[UF[A]] < UF_SIZE[UF[B]]) ? UF[B] : UF[A];
    
    for(int i = 1; i <= V; i++)
        if(UF[i] == smaller)
            UF[i] = larger;
    
    UF_SIZE[larger] += UF_SIZE[smaller];
    UF_SIZE[smaller] = 0;
    
    return larger;
}

bool find(int A, int B) // if A & B connected returns true, else return false
{
    if(UF[A] == UF[B])
        return true;
    
    return false;
}

bool compare(pairs A, pairs B)
{
    if (A.edge == B.edge)
        return A.a < B.a;
    else
        return A.edge < B.edge;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<pairs> edges;
    int V, E, result; result = 0;
    std::cin >> V >> E;
    
    for(int i=0; i<MAX_VERTICES; i++)
    {
        UF[i] = i;
        UF_SIZE[i] = 0;
    }
    
    for(int i=0; i<E; i++)
    {
        pairs temp;
        std::cin >> temp.a >> temp.b >> temp.edge;
        temp.inMST = false;
        edges.push_back(temp);
    }
    
    // sort edges in ascending order
    std::sort(edges.begin(), edges.end(), compare);
    
    // kruskal's algorithm
    int union_num = -1;
    for(std::vector<pairs>::iterator p = edges.begin(); p != edges.end(); p++)
        if(!find(p->a, p->b))
        {
            p->inMST = true;
            union_num = unite(p->a, p->b, V);
            MST[p->a].emplace_back(p->b, p->edge); // store in 2D vector MST
            MST[p->b].emplace_back(p->a, p->edge); // store in 2D vector MST
            result += p->edge;
        }
    
    // if there is no MST
    if(union_num == -1)
    {
        std::cout << "-1\n";
        return 0;
    }
    
    int min_result = INT_MAX;
    
    // process second best MST
    for(std::vector<pairs>::iterator i = edges.begin(); i != edges.end(); i++)
    {
        if(!(i->inMST)) // if edge i is not in MST
        {
            int temp_result = result + i->edge; // add edge i to MST
            
            // find cycle
            
            pairs max; max.edge = -1;
            for(std::vector<pairs>::iterator j = edges.begin(); j != edges.end(); j++) // find max edge in MST not equal to edge i
                if(j->inMST && j->edge > max.edge)
                    max = *j;
            
            temp_result -= max.edge;
            
            if(min_result > temp_result)
                min_result = temp_result;
        }
    }
    
    // if there is no second best MST
    if(min_result <= result)
    {
        std::cout << "-1\n";
        return 0;
    }
    
    std::cout << min_result << '\n';
    return 0;
}
*/
/*
2020-02-11
Lee Min Keon
Baekjoon Online Judge #2468
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX_GRID 100

typedef struct element
{
    int height;
    bool visited;
} element;

element grid[MAX_GRID][MAX_GRID];
int N, result = -1, max_height = -1, max_islands = 0;

void rain_shower()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(grid[i][j].height) grid[i][j].height--;
}

void dfs(int ver, int hor)
{
    grid[ver][hor].visited = true;
    
    if(ver > 0 && !(grid[ver-1][hor].visited) && grid[ver-1][hor].height) dfs(ver-1, hor);
    if(ver < N-1 && !(grid[ver+1][hor].visited) && grid[ver+1][hor].height) dfs(ver+1, hor);
    if(hor > 0 && !(grid[ver][hor-1].visited) && grid[ver][hor-1].height) dfs(ver, hor-1);
    if(hor < N-1 && !(grid[ver][hor+1].visited) && grid[ver][hor+1].height) dfs(ver, hor+1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            std::cin >> grid[i][j].height;
            if(grid[i][j].height > max_height)
                max_height = grid[i][j].height;
        }
    
    for(int a=0; a<N; a++)
        for(int b=0; b<N; b++)
            if(!(grid[a][b].visited) && grid[a][b].height)
            {
                dfs(a, b);
                max_islands++;
            }
    
    for(int i=1; i<=max_height; i++)
    {
        for(int a=0; a<N; a++)
            for(int b=0; b<N; b++)
                grid[a][b].visited = false;
        
        rain_shower();
        
        int islands = 0;
        
        for(int a=0; a<N; a++)
            for(int b=0; b<N; b++)
                if(!(grid[a][b].visited) && grid[a][b].height)
                {
                    dfs(a, b);
                    islands++;
                }
        
        if(islands > max_islands)
            max_islands = islands;
    }
    
    std::cout << max_islands << std::endl;
    
    return 0;
}
*/
/*
2020-02-12
Lee Min Keon
Baekjoon Online Judge #11437
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX_NODE 500001
#define MAX_HEIGHT 100

typedef struct list_node
{
    std::vector<int> node;
    int depth;
} list_node;

list_node tree[MAX_NODE];
int up[MAX_NODE][MAX_HEIGHT];

int LCA(int u, int v)
{
    int u_i = 0, v_i = 0, u_depth = tree[u].depth, v_depth = tree[v].depth;
    while(u_depth > v_depth) { u_i++; u_depth--; }
    while(u_depth < v_depth) { v_i++; v_depth--; }
    
    while(up[u][u_i] != 1 && up[v][v_i] != 1)
    {
        if(up[u][u_i] == up[v][v_i]) return up[u][u_i];
        u_i++;
        v_i++;
    }
    
    return 1;
}

void dfs(int index, int parent, int depth)
{
    tree[index].depth = depth;
    for(int i = 1; i <= depth; i++)
        up[index][i] = up[parent][i - 1];
    
    for(auto i : tree[index].node)
        if(i != parent)
            dfs(i, index, depth + 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX_NODE; i++)
    {
        tree[i].depth = 0;
        for(int j = 0; j < MAX_HEIGHT; j++)
            up[i][j] = 0;
        up[i][0] = i;
    }
    
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        
        tree[node1].node.push_back(node2);
        tree[node2].node.push_back(node1);
    }
    
    dfs(1, 0, 0);
    
    int M;
    std::cin >> M;
    std::vector<int> result;
    
    for(int i = 0; i < M; i++)
    {
        int u, v;
        std::cin >> u >> v;
        result.push_back(LCA(u, v));
    }
    
    for(auto i = result.begin(); i != result.end(); i++)
        std::cout << *i << '\n';
    
    return 0;
}
*/
/*
2020-02-12
Lee Min Keon
Baekjoon Online Judge #11438 naive approach (without dp) (time limit excess)
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX_NODE 100001

typedef struct list_node
{
    std::vector<int> node;
    int parent;
    int depth;
} list_node;

list_node tree[MAX_NODE];

int LCA(int u, int v)
{
    int max_repeat = tree[u].depth - tree[v].depth < 0 ? tree[v].depth - tree[u].depth : tree[u].depth - tree[v].depth;
    
    if(tree[u].depth > tree[v].depth)
        for(int i = 0; i < max_repeat; i++)
            u = tree[u].parent;
    
    if(tree[u].depth < tree[v].depth)
        for(int i = 0; i < max_repeat; i++)
            v = tree[v].parent;
    
    while(u && v)
    {
        if(u == v) return u;
        
        u = tree[u].parent;
        v = tree[v].parent;
    }
    
    return -1;
}

void DFS(int index, int parent, int depth)
{
    tree[index].parent = parent;
    tree[index].depth = depth;
    
    for(auto i : tree[index].node)
        if(i != parent)
            DFS(i, index, depth + 1);
}

int main()
{
    for(int i = 0; i < MAX_NODE; i++)
        tree[i].depth = tree[i].parent = 0;
    
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        
        tree[node1].node.push_back(node2);
        tree[node2].node.push_back(node1);
    }
    
    
    DFS(1, 0, 0);
    
    int M;
    std::cin >> M;
    std::vector<int> result;
    
    for(int i = 0; i < M; i++)
    {
        int u, v;
        std::cin >> u >> v;
        result.push_back(LCA(u, v));
    }
    
    for(auto i = result.begin(); i != result.end(); i++)
        std::cout << *i << '\n';
    
    return 0;
}
*/
/*
2020-02-12
Lee Min Keon
Baekjoon Online Judge #11438 dp (memory limit excess)
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX_NODE 100001

typedef struct list_node
{
    std::vector<int> node;
    int depth;
} list_node;

list_node tree[MAX_NODE];

int LCA(std::vector<std::vector<int>>& DP, int u, int v)
{
    int u_i = 0, v_i = 0, u_depth = tree[u].depth, v_depth = tree[v].depth;
    if(u_depth > v_depth)
    {
        u_i += u_depth - v_depth;
        u_depth -= u_depth - v_depth;
    }
    if(u_depth < v_depth)
    {
        v_i += v_depth - u_depth;
        v_depth -= v_depth - u_depth;
    }
    
    while(DP[u][u_i] != 1)
    {
        if(DP[u][u_i] == DP[v][v_i])
            return DP[u][u_i];
        
        u_i++; v_i++;
    }
    
    return 1;
}

void DFS(int index, int parent, int depth)
{
    tree[index].depth = depth;
    
    for(auto next : tree[index].node)
        if(next != parent)
            DFS(next, index, depth + 1);
}

void DFS_DP(std::vector<std::vector<int>>& DP, int index, int parent)
{
    DP[index].push_back(index);
    for(int i = 0; i < DP[parent].size(); i++)
        DP[index].push_back(DP[parent][i]);
    
    for(auto next : tree[index].node)
        if(next != parent)
            DFS_DP(DP, next, index);
}

int main()
{
    for(int i = 0; i < MAX_NODE; i++)
        tree[i].depth = 0;
    
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        
        tree[node1].node.push_back(node2);
        tree[node2].node.push_back(node1);
    }
    
    DFS(1, 0, 0);
    
    std::vector<std::vector<int>> DP(N + 1);
    
    DFS_DP(DP, 1, 0);
    
    int M;
    std::cin >> M;
    std::vector<int> result;
    
    for(int i = 0; i < M; i++)
    {
        int u, v;
        std::cin >> u >> v;
        result.push_back(LCA(DP, u, v));
    }
    
    for(auto i = result.begin(); i != result.end(); i++)
        std::cout << *i << '\n';
    
    return 0;
}
*/
/*
2020-02-12
Lee Min Keon
Baekjoon Online Judge #11438 dp (memoization) (memory limit excess)
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX_NODE 100001 // max number possible

typedef struct list_node // node for adjacency list & tree
{
    std::vector<int> node;
    int parent;
    int depth;
} list_node;

list_node tree[MAX_NODE]; // adjacency list for tree

int LCA(std::vector<std::vector<int>>& DP, int u, int v)
{
    int u_i = 0, v_i = 0, u_depth = tree[u].depth, v_depth = tree[v].depth;
    int dp_u = u, dp_v = v;
    
    if(DP[u].empty()) // if DP[u] is empty, we fill it up
    {
        DP[u].push_back(dp_u);
        for(int i = 0; i < u_depth; i++)
        {
            DP[u].push_back(tree[dp_u].parent);
            dp_u = tree[dp_u].parent;
        }
    }
    
    if(DP[v].empty()) // if DP[v] is empty, we fill it up
    {
        DP[v].push_back(dp_v);
        for(int i = 0; i < v_depth; i++)
        {
            DP[v].push_back(tree[dp_v].parent);
            dp_v = tree[dp_v].parent;
        }
    }
    
    if(u_depth > v_depth) // if the depth of nodes are different, adjust the depth with index
    {
        u_i += u_depth - v_depth;
        u_depth -= u_depth - v_depth;
    }
    if(u_depth < v_depth) // if the depth of nodes are different, adjust the depth with index
    {
        v_i += v_depth - u_depth;
        v_depth -= v_depth - u_depth;
    }
    
    while(DP[u][u_i] != 1) // calculate the LCA starting from the same depth
    {
        if(DP[u][u_i] == DP[v][v_i])
            return DP[u][u_i];
        
        u_i++; v_i++;
    }
    
    return 1; // if there is no return within the while statement, return default value (root is the LCA)
}

void DFS(int index, int parent, int depth)
{
    tree[index].parent = parent;
    tree[index].depth = depth;
    
    for(auto next : tree[index].node) // for every child node of current node
        if(next != parent)
            DFS(next, index, depth + 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX_NODE; i++) // tree initialization
        tree[i].parent = tree[i].depth = 0;
    
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N - 1; i++) // input the link data into the adjacency list
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        
        tree[node1].node.push_back(node2);
        tree[node2].node.push_back(node1);
    }
    
    DFS(1, 0, 0); // perform DFS to scrutinize tree structure
    
    std::vector<std::vector<int>> DP(N + 1); // dynamic array DP
    
    int M;
    std::cin >> M;
    std::vector<int> result; // dynamic array for storing the LCA calculation results
    
    for(int i = 0; i < M; i++) // for M, calculate the LCA for every input pair
    {
        int u, v;
        std::cin >> u >> v;
        result.push_back(LCA(DP, u, v));
    }
    
    for(auto i = result.begin(); i != result.end(); i++) // output the results of the calculation done above
        std::cout << *i << '\n';
    
    return 0;
}
*/
/*
2020-02-11
Lee Min Keon
Baekjoon Online Judge #1626 Union Find & Kruskal Implementation
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

#define MAX_VERTICES 50001
#define MAX_EDGES 200001
#define MAX_HEIGHT 20

typedef struct pairs
{
    int a;
    int b;
    int edge;
    bool inMST;
} pairs;

typedef struct list_node // node for adjacency list & tree
{
    std::vector<int> node;
    int parent;
    int depth;
} list_node;

int UF[MAX_VERTICES], UF_SIZE[MAX_VERTICES], DP[MAX_VERTICES][MAX_HEIGHT]; // disjoint set for MST cycle check
list_node MST[MAX_VERTICES]; // adj list for MST

// TODO: fix MST declaration, depth calculation, parent calculation, etc...

int LCA(int u, int v)
{
    if(MST[u].depth > MST[v].depth) std::swap(u, v); // set u the higher element for the convenience of calculation
    
    int dif = MST[v].depth - MST[u].depth;
    if(dif) // if the depth of nodes are different, adjust the depth with index
        for(int i = 0; i < MAX_HEIGHT && v; i++)
            if((1 << i) & dif) // if there is enough space to jump
                v = DP[v][i];
    
    if(u == v) return u; // the case when u or v is an ancestor of each other
    
    for(int i = MAX_HEIGHT - 1; i >= 0; i--) // take the largest available jump (i.e. start from biggest number)
        if(DP[u][i] != DP[v][i]) // if jump is available (within range)
        {
            u = DP[u][i]; // take the jump
            v = DP[v][i];
        }
    
    return DP[u][0]; // return the direct parent
}

void fill_dp(int index) // fills the DP array at index "index" (e.g. DP[index])
{
    DP[index][0] = MST[index].parent;
    for(int i = 1; i < MAX_HEIGHT; i++)
        DP[index][i] = DP[DP[index][i - 1]][i - 1];
}

void DFS(int index, int parent, int depth)
{
    MST[index].parent = parent;
    MST[index].depth = depth;
    
    fill_dp(index);
    
    for(auto next : MST[index].node) // for every child node of current node
        if(next != parent)
            DFS(next, index, depth + 1);
}

int unite(int A, int B, int& V)
{
    int smaller = (UF_SIZE[UF[A]] < UF_SIZE[UF[B]]) ? UF[A] : UF[B];
    int larger = (UF_SIZE[UF[A]] < UF_SIZE[UF[B]]) ? UF[B] : UF[A];
    
    for(int i = 1; i <= V; i++)
        if(UF[i] == smaller)
            UF[i] = larger;
    
    UF_SIZE[larger] += UF_SIZE[smaller];
    UF_SIZE[smaller] = 0;
    
    return larger;
}

bool find(int A, int B) // if A & B connected returns true, else return false
{
    if(UF[A] == UF[B])
        return true;
    
    return false;
}

bool compare(pairs A, pairs B)
{
    if (A.edge == B.edge)
        return A.a < B.a;
    else
        return A.edge < B.edge;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<pairs> edges;
    int V, E, MST_result; MST_result = 0;
    std::cin >> V >> E;
    
    for(int i = 0; i < MAX_VERTICES; i++)
    {
        UF[i] = i;
        UF_SIZE[i] = 0;
        for(int j = 0; j < MAX_HEIGHT; j++)
            DP[i][j] = 0;
    }
    
    for(int i = 0; i < E; i++)
    {
        pairs temp;
        std::cin >> temp.a >> temp.b >> temp.edge;
        temp.inMST = false;
        edges.push_back(temp);
    }
    
    // sort edges in ascending order
    std::sort(edges.begin(), edges.end(), compare);
    
    // kruskal's algorithm
    int union_num = -1;
    for(auto p = edges.begin(); p != edges.end(); p++)
        if(!find(p->a, p->b))
        {
            p->inMST = true;
            union_num = unite(p->a, p->b, V);
            MST[p->a].emplace_back(p->b, p->edge); // store in 2D vector MST
            MST[p->b].emplace_back(p->a, p->edge); // store in 2D vector MST
            MST_result += p->edge;
        }
    
    // if there is no MST
    if(union_num == -1)
    {
        std::cout << "-1\n";
        return 0;
    }
    
    int min_result = INT_MAX;
    
    // process second best MST
    for(auto i = edges.begin(); i != edges.end(); i++)
        if(!(i->inMST)) // if edge i is not in MST
        {
            int temp_result = MST_result + i->edge; // add edge i to MST
            
            // find cycle
            
            pairs max; max.edge = -1;
            for(auto j = edges.begin(); j != edges.end(); j++) // find max edge in MST not equal to edge i
                if(j->inMST && j->edge > max.edge)
                    max = *j;
            
            temp_result -= max.edge;
            
            if(min_result > temp_result)
                min_result = temp_result;
        }
    
    // if there is no second best MST
    if(min_result <= MST_result)
    {
        std::cout << "-1\n";
        return 0;
    }
    
    std::cout << min_result << '\n';
    return 0;
}
*/
/*
2020-02-13
Lee Min Keon
Baekjoon Online Judge #2178 BFS
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#define MAX 101

int N, M, grid[MAX][MAX];
std::queue<std::tuple<int, int, int>> Q; // x, y, count

void BFS()
{
    Q.push(std::make_tuple(0, 0, 1));
    std::tuple<int, int, int> now;
    
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        
        if(grid[std::get<0>(now)][std::get<1>(now)]) continue;// if visited
        
        grid[std::get<0>(now)][std::get<1>(now)] = std::get<2>(now);
        
        if(std::get<0>(now) > 0 && !grid[std::get<0>(now) - 1][std::get<1>(now)])
            Q.push(std::make_tuple(std::get<0>(now) - 1, std::get<1>(now), std::get<2>(now) + 1));
        if(std::get<0>(now) < N - 1 && !grid[std::get<0>(now) + 1][std::get<1>(now)])
            Q.push(std::make_tuple(std::get<0>(now) + 1, std::get<1>(now), std::get<2>(now) + 1));
        if(std::get<1>(now) > 0 && !grid[std::get<0>(now)][std::get<1>(now) - 1])
            Q.push(std::make_tuple(std::get<0>(now), std::get<1>(now) - 1, std::get<2>(now) + 1));
        if(std::get<1>(now) < M - 1 && !grid[std::get<0>(now)][std::get<1>(now) + 1])
            Q.push(std::make_tuple(std::get<0>(now), std::get<1>(now) + 1, std::get<2>(now) + 1));
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            grid[i][j] = -1;
    
    std::cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        std::string buf;
        std::cin >> buf;
        for(int j = 0; j < M; j++)
            if(buf[j] == '1')
                grid[i][j] = 0;
    }
    
    BFS();
    
    std::cout << grid[N - 1][M - 1] << '\n';
    
    return 0;
}
*/
/*
2020-02-13
Lee Min Keon
Baekjoon Online Judge #2644
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX_PEOPLE 101

typedef struct node
{
    std::vector<int> nodes;
    bool visited;
} node;

int N, M, X, Y, result = -1;
bool flag = false;
node tree[MAX_PEOPLE];

void DFS(int current, int& target, int count)
{
    if(flag) return;
    
    if(current == target)
    {
        result = count;
        flag = true;
        return;
    }
    
    tree[current].visited = true;
    
    for(auto next : tree[current].nodes)
        if(!tree[next].visited)
            DFS(next, target, count + 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX_PEOPLE; i++)
        tree[i].visited = 0;
    
    std::cin >> N >> X >> Y >> M;
    
    for(int i = 0; i < M; i++)
    {
        int x, y;
        std::cin >> x >> y;
        
        tree[x].nodes.push_back(y);
        tree[y].nodes.push_back(x);
    }
    
    DFS(X, Y, 0);
    
    std::cout << result << '\n';
    
    return 0;
}
*/
/*
2020-02-13
Lee Min Keon
Baekjoon Online Judge #2606
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>
#include <queue>

#define MAX_COMPUTERS 101

typedef struct node
{
    std::vector<int> nodes;
    bool visited;
} node;

int N, M, count = -1;
node graph[MAX_COMPUTERS];
std::queue<int> Q;

void BFS(int start)
{
    Q.push(start);
    
    while(!Q.empty())
    {
        int current = Q.front();
        Q.pop();
        
        for(auto next : graph[current].nodes)
            if(!graph[next].visited)
            {
                graph[next].visited = true;
                count++;
                
                Q.push(next);
            }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX_COMPUTERS; i++)
        graph[i].visited = false;
    
    std::cin >> N >> M;
    
    for(int i = 0; i < M; i++)
    {
        int com1, com2;
        std::cin >> com1 >> com2;
        
        graph[com1].nodes.push_back(com2);
        graph[com2].nodes.push_back(com1);
    }
    
    BFS(1);
    
    std::cout << count << '\n';
    
    return 0;
}
*/
/*
2020-02-13
Lee Min Keon
Baekjoon Online Judge #3009
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int points[3][2], result[2];
    
    for(int i = 0; i < 3; i++)
        std::cin >> points[i][0] >> points[i][1];
    
    for(int i = 0; i< 2; i++)
    {
        int one = points[0][i], two;
        bool four_same = true;
        for(int j = 0; j < 3; j++)
            if(one != points[j][i])
            {
                two = points[j][i];
                four_same = false;
            }
        
        if(four_same) result[i] = one;
        else
        {
            int count = 0;
            for(int j = 0; j < 3; j++)
                if(one == points[j][i])
                    count++;
            
            if(count == 1) result[i] = one;
            else result[i] = two;
        }
    }
    
    std::cout << result[0] << ' ' << result[1] << '\n';
    
    return 0;
}
*/
/*
2020-02-13
Lee Min Keon
Baekjoon Online Judge #4153
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    while(true)
    {
        int edges[3];
        std::cin >> edges[0] >> edges[1] >> edges[2];
        
        if(!edges[0] && !edges[1] && !edges[2]) break;
        
        int max = 0;
        for(int i = 0; i < 3; i++)
            if(edges[i] > edges[max])
                max = i;
        
        int sum = 0;
        for(int i = 0; i < 3; i++)
            if(i != max)
                sum += edges[i] * edges[i];
        
        if(sum == edges[max] * edges[max])
            std::cout << "right\n";
        else
            std::cout << "wrong\n";
    }
    
    return 0;
}
*/
/*
2020-02-13
Lee Min Keon
Baekjoon Online Judge #1085
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <cstdio>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int arr[4], x, y, w, h;
    
    std::cin >> x >> y >> w >> h;
    
    arr[0] = (int)abs(x - w);
    arr[1] = (int)abs(x);
    arr[2] = (int)abs(y - h);
    arr[3] = (int)abs(y);
    
    int min = 10000;
    for(int i = 0; i < 4; i++)
        if(arr[i] < min)
            min = arr[i];
    
    std::cout << min << '\n';
    
    return 0;
}
*/
/*
2020-02-13
Lee Min Keon
Baekjoon Online Judge #11725
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX 100001

typedef struct node
{
    std::vector<int> nodes;
    int parent;
} node;

node tree[MAX];
int N;

void DFS(int current, int parent)
{
    tree[current].parent = parent;
    
    for(auto next : tree[current].nodes)
        if(next != parent)
            DFS(next, current);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        tree[i].parent = 0;
    
    std::cin >> N;
    
    for(int i = 1; i < N; i++)
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        
        tree[node1].nodes.push_back(node2);
        tree[node2].nodes.push_back(node1);
    }
    
    DFS(1, 0);
    
    for(int i = 2; i <= N; i++)
        std::cout << tree[i].parent << '\n';
    
    return 0;
}
*/
/*
2020-02-14
Lee Min Keon
Baekjoon Online Judge #1167
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <queue>
#include <vector>

#define MAX 100001

typedef std::pair<int, int> pair;

typedef struct node
{
    int to;
    int cost;
    node(int to, int cost) : to(to), cost(cost) {}
} node;

typedef struct tree_node
{
    std::vector<node> nodes;
    bool leaf;
    bool visited;
} tree_node;

tree_node tree[MAX];
std::queue<pair> Q; // first: edge, second: cost
int N, F, max = -1;

void BFS(int start, int& target)
{
    tree[start].visited = true;
    Q.push(pair(start, 0));
    
    while(!Q.empty())
    {
        pair now = Q.front();
        Q.pop();
        
        for(auto next : tree[now.first].nodes)
            if(!tree[next.to].visited && tree[next.to].leaf)
            {
                tree[next.to].visited = true;
                
                if(now.second + next.cost > max)
                {
                    max = now.second + next.cost;
                    target = next.to;
                }
            }
        
        for(auto next : tree[now.first].nodes)
            if(!tree[next.to].visited)
            {
                tree[next.to].visited = true;
                
                Q.push(pair(next.to, now.second + next.cost));
            }
    }
}

void reset_visited(int& N)
{
    for(int i = 1; i <= N; i++)
        tree[i].visited = false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        tree[i].leaf = tree[i].visited = false;
    
    std::cin >> N;
 
    for(int i = 1; i <= N; i++)
    {
        int from, count = 0;
        std::cin >> from;
        
        while(true)
        {
            int to, cost;
            std::cin >> to;
            if(to == -1) break;
            std::cin >> cost;
            
            tree[from].nodes.emplace_back(node(to, cost));
            count++;
        }
        
        if(count == 1)
            tree[from].leaf = true;
    }
    
    for(int i = 1; i <= N; i++)
        if(tree[i].leaf)
        {
            BFS(i, F);
            reset_visited(N);
            max = -1;
            break;
        }
    
    BFS(F, F);
    
    std::cout << max << '\n';
    
    return 0;
}
*/
/*
2020-02-15
Lee Min Keon
Baekjoon Online Judge #9498
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int score;
    std::cin >> score;
    
    if(score >= 90)
        std::cout << "A\n";
    else if(score >= 80)
        std::cout << "B\n";
    else if(score >= 70)
        std::cout << "C\n";
    else if(score >= 60)
        std::cout << "D\n";
    else
        std::cout << "F\n";
    
    return 0;
}
*/
/*
2020-02-15
Lee Min Keon
Baekjoon Online Judge #1967
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <queue>
#include <vector>

#define MAX 10001

typedef std::pair<int, int> pair;

typedef struct node
{
    int to;
    int cost;
    node(int to, int cost) : to(to), cost(cost) {}
} node;

typedef struct tree_node
{
    std::vector<node> nodes;
    bool leaf;
    bool visited;
} tree_node;

tree_node tree[MAX];
std::queue<pair> Q; // first: edge, second: cost
int N, F, max = -1;

void BFS(int start, int& target)
{
    tree[start].visited = true;
    Q.push(pair(start, 0));
    
    while(!Q.empty())
    {
        pair now = Q.front();
        Q.pop();
        
        for(auto next : tree[now.first].nodes)
            if(!tree[next.to].visited && tree[next.to].leaf)
            {
                tree[next.to].visited = true;
                
                if(now.second + next.cost > max)
                {
                    max = now.second + next.cost;
                    target = next.to;
                }
            }
        
        for(auto next : tree[now.first].nodes)
            if(!tree[next.to].visited)
            {
                tree[next.to].visited = true;
                
                Q.push(pair(next.to, now.second + next.cost));
            }
    }
}

void reset_visited(int& N)
{
    for(int i = 1; i <= N; i++)
        tree[i].visited = false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        tree[i].leaf = tree[i].visited = false;
    
    std::cin >> N;
    
    for(int i = 1; i < N; i++)
    {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        
        tree[from].nodes.emplace_back(node(to, cost));
        tree[to].nodes.emplace_back(node(from, cost));
    }
    
    for(int i = 1; i <= N; i++)
        if(tree[i].nodes.size() == 1)
            tree[i].leaf = true;
    
    for(int i = 1; i <= N; i++)
        if(tree[i].leaf)
        {
            BFS(i, F);
            reset_visited(N);
            max = -1;
            break;
        }
    
    BFS(F, F);
    
    std::cout << max << '\n';
    
    return 0;
}
*/
/*
2020-02-15
Lee Min Keon
Baekjoon Online Judge #1991
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 26

typedef struct tree_node
{
    int left;
    int right;
} tree_node;

tree_node tree[MAX];
int N;

void PRE(int now)
{
    std::cout << (char)(now + 'A');
    if(tree[now].left != -1) PRE(tree[now].left);
    if(tree[now].right != -1) PRE(tree[now].right);
}

void IN(int now)
{
    if(tree[now].left != -1) IN(tree[now].left);
    std::cout << (char)(now + 'A');
    if(tree[now].right != -1) IN(tree[now].right);
}

void POST(int now)
{
    if(tree[now].left != -1) POST(tree[now].left);
    if(tree[now].right != -1) POST(tree[now].right);
    std::cout << (char)(now + 'A');
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        tree[i].left = tree[i].right = -1;
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        char parent, l_child, r_child;
        std::cin >> parent >> l_child >> r_child;
        
        if(l_child != '.') tree[parent - 'A'].left = l_child - 'A';
        if(r_child != '.') tree[parent - 'A'].right = r_child - 'A';
    }
    
    PRE(0); std::cout << '\n';
    IN(0); std::cout << '\n';
    POST(0); std::cout << '\n';
    
    return 0;
}
*/
/*
2020-02-16
Lee Min Keon
Baekjoon Online Judge #10870
mkleeboy3@naver.com
*/
/*
#include <iostream>

int fibo(int n)
{
    if(!n || n == 1)
        return n;
    
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    std::ios_base::sync_with_stdio();
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    
    std::cout << fibo(N) << '\n';
    
    return 0;
}
*/
/*
2020-02-16
Lee Min Keon
Baekjoon Online Judge #1991
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 100001

typedef struct node
{
    int parent;
    int left;
    int right;
} node;

int in[MAX], post[MAX], pre[MAX];
int N;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        in[i] = post[i] = pre[i] = 0;
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
        std::cin >> in[i];
    
    for(int i = 0; i < N; i++)
        std::cin >> post[i];
    
    for(int i = 0; i < N; i++)
    {
        if(in[i] == post[i])
        {
            
            // 수식 트리 이용하자
            
            
        }
        else
        {
            
            
            
        }
        
        
        
        
    }
    
    return 0;
}
*/
/*
2020-02-16
Lee Min Keon
Baekjoon Online Judge #2798
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 100

int N, M, min, cards[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        cards[i] = 0;
    
    std::cin >> N >> M;
    min = M + 1;
    
    for(int i = 0; i < N; i++)
        std::cin >> cards[i];
    
    for(int i = 0; i < N - 2; i++)
        for(int j = i + 1; j < N - 1; j++)
            for(int k = j + 1; k < N; k++)
            {
                int sum = cards[i] + cards[j] + cards[k];
                if(M - sum >= 0 && M - sum < min)
                    min = M - sum;
            }
    
    std::cout << M - min << '\n';
    
    return 0;
}
*/
/*
2020-02-16
Lee Min Keon
Baekjoon Online Judge #1018
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>
#include <climits>

#define UNIT 8
#define MAX 50

int N, M, min = INT_MAX;
bool grid[MAX][MAX]; // false: B, true: W

void try_cut(int ver, int hor)
{
    int count = 0;
    bool start = grid[ver][hor];
    for(int i = ver; i < ver + UNIT; i++, start = !start)
        for(int j = hor; j < hor + UNIT; j++)
        {
            if((j % 2) == (hor % 2) && grid[i][j] == !start) count++;
            if((j % 2) != (hor % 2) && grid[i][j] == start) count++;
        }
    
    if(count < min)
        min = count;
    
    count = 0;
    start = !grid[ver][hor];
    for(int i = ver; i < ver + UNIT; i++, start = !start)
        for(int j = hor; j < hor + UNIT; j++)
        {
            if((j % 2) == (hor % 2) && grid[i][j] == !start) count++;
            if((j % 2) != (hor % 2) && grid[i][j] == start) count++;
        }
    
    if(count < min)
        min = count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            grid[i][j] = false;
    
    std::cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        std::string input;
        std::cin >> input;
        
        for(int j = 0; j < M; j++)
            if(input[j] == 'W')
                grid[i][j] = true;
    }
    
    for(int i = 0; i <= N - UNIT; i++)
        for(int j = 0; j <= M - UNIT; j++)
            try_cut(i, j);
    
    std::cout << min << '\n';
    
    return 0;
}
*/
/*
2020-02-17
Lee Min Keon
Baekjoon Online Judge #1436
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <string>

#define MAX 10000

int N, count = 0;

bool has_six(const std::string& num)
{
    for(auto i = num.begin(); i != num.end() - 1; i++)
        if(*i == '6' && *(i + 1) == '6' && *(i + 2) == '6')
            return true;
    
    return false;
}

long long int iterate()
{
    long long int num = 666;
    while(count < N)
    {
        if(has_six(std::to_string(num)))
            count++;
        
        num++;
    }
    
    return num - 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    std::cout << iterate() << '\n';
    
    return 0;
}
*/
/*
2020-02-17
Lee Min Keon
Baekjoon Online Judge #11650
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>

#define MAX 100001

typedef struct pair
{
    int x;
    int y;
    
    pair() : x(0), y(0) {}
    
    pair(int x, int y) : x(x), y(y) {}
} pair;

pair arr[MAX];
int N;

bool compare(const pair& a, const pair& b)
{
    if(a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
        std::cin >> arr[i].x >> arr[i].y;
    
    pair* ptr = arr;
    
    std::sort(ptr, ptr + N, compare);
    
    for(int i = 0; i < N; i++)
        std::cout << arr[i].x << ' ' << arr[i].y << '\n';
    
    return 0;
}
*/
/*
2020-02-17
Lee Min Keon
Baekjoon Online Judge #11650
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>

#define MAX 100001

struct pair
{
    int x;
    int y;
    
    pair() : x(0), y(0) {}
    
    pair(int x, int y) : x(x), y(y) {}
    
    bool operator<(const pair& obj) const
    {
        if(x == obj.x)
            return y < obj.y;
        else
            return x < obj.x;
    }
};

pair arr[MAX];
int N;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
        std::cin >> arr[i].x >> arr[i].y;
    
    pair* ptr = arr;
    
    std::sort(ptr, ptr + N);
    
    for(int i = 0; i < N; i++)
        std::cout << arr[i].x << ' ' << arr[i].y << '\n';
    
    return 0;
}
*/
/*
2020-02-17
Lee Min Keon
Baekjoon Online Judge #11651
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>

#define MAX 100001

struct pair
{
    int x;
    int y;
    
    pair() : x(0), y(0) {}
    
    pair(int x, int y) : x(x), y(y) {}
    
    bool operator<(const pair& obj) const
    {
        if(y == obj.y)
            return x < obj.x;
        else
            return y < obj.y;
    }
};

pair arr[MAX];
int N;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
        std::cin >> arr[i].x >> arr[i].y;
    
    pair* ptr = arr;
    
    std::sort(ptr, ptr + N);
    
    for(int i = 0; i < N; i++)
        std::cout << arr[i].x << ' ' << arr[i].y << '\n';
    
    return 0;
}
*/
/*
2020-02-17
Lee Min Keon
Baekjoon Online Judge #10814
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <algorithm>
#include <string>

#define MAX 100000

struct pair
{
    int age;
    int join_date;
    std::string name;
    pair() : age(0), join_date(0), name("") {}
};

pair arr[MAX];
int N, indices[MAX];

bool compare(const int& a, const int& b)
{
    if(arr[a].age == arr[b].age)
        return arr[a].join_date < arr[b].join_date;
    else
        return arr[a].age < arr[b].age;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        indices[i] = i;
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        std::cin >> arr[i].age;
        arr[i].join_date = i;
        std::cin >> arr[i].name;
    }
    
    int* ptr = indices;
    
    std::sort(ptr, ptr + N, compare);
    
    for(int i = 0; i < N; i++)
        std::cout << arr[indices[i]].age << ' ' << arr[indices[i]].name << '\n';
    
    return 0;
}
*/
/*
2020-02-18
Lee Min Keon
Baekjoon Online Judge #15649
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 9

int N, M, values[MAX];
bool visited[MAX];

void search(int level)
{
    if(M < level)
    {
        for(int i = 1; i < level; i++)
            std::cout << values[i] << ' ';
        std::cout << '\n';
        
        return;
    }
    
    for(int i = 1; i <= N; i++)
        if(!visited[i])
        {
            values[level] = i;
            visited[i] = true;
            search(level + 1);
            visited[i] = false;
        }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
    {
        values[i] = 0;
        visited[i] = false;
    }
    
    std::cin >> N >> M;
    
    search(1);
    
    return 0;
}
*/
/*
2020-02-18
Lee Min Keon
Baekjoon Online Judge #15650
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 9

int N, M, values[MAX];
bool visited[MAX];

void search(int current, int level)
{
    if(M < level)
    {
        for(int i = 1; i < level; i++)
            std::cout << values[i] << ' ';
        std::cout << '\n';
        
        return;
    }
    
    for(int i = current; i <= N; i++)
        if(!visited[i])
        {
            values[level] = i;
            visited[i] = true;
            search(i, level + 1);
            visited[i] = false;
        }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
    {
        values[i] = 0;
        visited[i] = false;
    }
    
    std::cin >> N >> M;
    
    search(1, 1);
    
    return 0;
}
*/
/*
2020-02-18
Lee Min Keon
Baekjoon Online Judge #15651
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 9

int N, M, values[MAX];
bool visited[MAX];

void search(int level)
{
    if(M < level)
    {
        for(int i = 1; i < level; i++)
            std::cout << values[i] << ' ';
        std::cout << '\n';
        
        return;
    }
    
    for(int i = 1; i <= N; i++)
    {
        values[level] = i;
        search(level + 1);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
    {
        values[i] = 0;
        visited[i] = false;
    }
    
    std::cin >> N >> M;
    
    search(1);
    
    return 0;
}
*/
/*
2020-02-18
Lee Min Keon
Baekjoon Online Judge #15652
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 9

int N, M, values[MAX];
bool visited[MAX];

void search(int current, int level)
{
    if(M < level)
    {
        for(int i = 1; i < level; i++)
            std::cout << values[i] << ' ';
        std::cout << '\n';
        
        return;
    }
    
    for(int i = current; i <= N; i++)
    {
        values[level] = i;
        search(i, level + 1);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
    {
        values[i] = 0;
        visited[i] = false;
    }
    
    std::cin >> N >> M;
    
    search(1, 1);
    
    return 0;
}
*/
/*
2020-02-18
Lee Min Keon
Baekjoon Online Judge #9663
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 15

int N, count = 0;
bool col[MAX], l_diag[MAX * 2 - 1], r_diag[MAX * 2 - 1];

void queen(int row)
{
    for(int i = 0; i < N; i++)
        if(!col[i] && !r_diag[i + row] && !l_diag[i - row + N - 1])
        {
            if(row == N - 1)
            {
                count++;
                return;
            }
            
            col[i] = r_diag[i + row] = l_diag[i - row + N - 1] = true;
            queen(row + 1);
            col[i] = r_diag[i + row] = l_diag[i - row + N - 1] = false;
        }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        col[i] = false;
    
    for(int i = 0; i < MAX * 2 + 1; i++)
        l_diag[i] = r_diag[i] = false;
    
    std::cin >> N;
    
    queen(0);
    
    std::cout << count << '\n';
    
    return 0;
}
*/
/*
2020-02-19
Lee Min Keon
Baekjoon Online Judge #2580 time limit exceeded
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 9
#define NUM 10
#define SQUARE 3

int count = 0, grid[MAX][MAX], ver[NUM][MAX], hor[NUM][MAX], square[NUM][SQUARE][SQUARE];
bool found = false;

void print_grid()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
            std::cout << grid[i][j] << ' ';
        std::cout << '\n';
    }
}

void search(int life)
{
    if(found) return;
    
    if(!life)
    {
        print_grid();
        found = true;
        return;
    }
    
    for(int i = 0; i < MAX && !found; i++)
        for(int j = 0; j < MAX && !found; j++)
            if(!grid[i][j])
            {
                bool change = false;
                
                for(int k = 1; k < NUM; k++)
                    if(!hor[k][i] && !ver[k][j] && !square[k][i / 3][j / 3])
                    {
                        change = true;
                        
                        grid[i][j] = k;
                        hor[k][i] = 1;
                        ver[k][j] = 1;
                        square[k][i / 3][j / 3] = 1;
                        
                        search(life - 1);
                        
                        grid[i][j] = 0;
                        hor[k][i] = 0;
                        ver[k][j] = 0;
                        square[k][i / 3][j / 3] = 0;
                    }
                
                if(!change) return;
            }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            grid[i][j] = ver[i][j] = hor[i][j] = 0;
    
    for(int i = 0; i < MAX; i++)
        ver[MAX][i] = hor[MAX][i] = 0;
    
    for(int i = 0; i < NUM; i++)
        for(int j = 0; j < SQUARE; j++)
            for(int k = 0; k < SQUARE; k++)
                square[i][j][k] = 0;
    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
        {
            int num;
            std::cin >> num;
            
            if(num)
                hor[num][i] = ver[num][j] = square[num][i / 3][j / 3] = 1;
            else
                count++;
            
            grid[i][j] = num;
        }
    
    search(count);
    
    return 0;
}
*/
/*
2020-02-19
Lee Min Keon
Baekjoon Online Judge #2580
mkleeboy3@naver.com
*/
/*
#include <iostream>

#define MAX 9
#define NUM 10
#define SQUARE 3

int grid[MAX][MAX], count = 0;
bool found = false, ver[NUM][MAX], hor[NUM][MAX], square[NUM][SQUARE][SQUARE];

void print_grid()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
            std::cout << grid[i][j] << ' ';
        std::cout << '\n';
    }
}

void search(int life)
{
    if(!life)
    {
        print_grid();
        found = true;
        return;
    }
    
    for(int i = 0; i < MAX && !found; i++)
        for(int j = 0; j < MAX && !found; j++)
            if(!grid[i][j])
            {
                for(int k = 1; k < NUM && !found; k++)
                    if(!hor[k][i] && !ver[k][j] && !square[k][i / 3][j / 3])
                    {
                        grid[i][j] = k;
                        hor[k][i] = true;
                        ver[k][j] = true;
                        square[k][i / 3][j / 3] = true;
                        
                        search(life - 1);
                        
                        grid[i][j] = 0;
                        hor[k][i] = false;
                        ver[k][j] = false;
                        square[k][i / 3][j / 3] = false;
                    }
                
                return;
            }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
        {
            grid[i][j] = 0;
            ver[i][j] = hor[i][j] = false;
        }
    
    for(int i = 0; i < MAX; i++)
        ver[MAX][i] = hor[MAX][i] = false;
    
    for(int i = 0; i < SQUARE; i++)
        for(int j = 0; j < SQUARE; j++)
            for(int k = 0; k < NUM; k++)
                square[k][i][j] = false;
    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
        {
            int num;
            std::cin >> num;
            
            if(num)
                hor[num][i] = ver[num][j] = square[num][i / 3][j / 3] = true;
            else
                count++;
            
            grid[i][j] = num;
        }
    
    search(count);
    
    return 0;
}
*/
/*
2020-02-19
Lee Min Keon
Baekjoon Online Judge #14888
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <climits>

#define MAX 11
#define OP 4

int N, nums[MAX], operators[OP];
int min = INT_MAX, max = INT_MIN;

void search(int index, int result)
{
    if(index == N)
    {
        if(result < min)
            min = result;
        
        if(result > max)
            max = result;
        
        return;
    }
    
    for(int i = 0; i < OP; i++)
        if(operators[i])
        {
            switch(i)
            {
                case 0:
                    operators[i]--;
                    search(index + 1, result + nums[index]);
                    operators[i]++;
                    break;
                case 1:
                    operators[i]--;
                    search(index + 1, result - nums[index]);
                    operators[i]++;
                    break;
                case 2:
                    operators[i]--;
                    search(index + 1, result * nums[index]);
                    operators[i]++;
                    break;
                case 3:
                    operators[i]--;
                    search(index + 1, result / nums[index]);
                    operators[i]++;
                    break;
            }
        }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
        std::cin >> nums[i];
    
    for(int i = 0; i < OP; i++)
        std::cin >> operators[i];
    
    search(1, nums[0]);
    
    std::cout << max << '\n' << min << '\n';
    
    return 0;
}
*/
/*
2020-02-19
Lee Min Keon
Baekjoon Online Judge #14889
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <climits>
#include <cmath>

#define MAX 20

int N, S[MAX][MAX], min = INT_MAX;
bool players[MAX];

void split(int index, int count)
{
    if(index == N)
    {
        if(!count)
        {
            int start = 0, link = 0;
            
            for(int i = 0; i < N - 1; i++)
                for(int j = i + 1; j < N; j++)
                    if(players[i] && players[j])
                        start += S[i][j] + S[j][i];
                    else if(!players[i] && !players[j])
                        link += S[i][j] + S[j][i];
            
            int contrast = (int)abs(start - link);
            
            if(contrast < min)
                min = contrast;
        }
        
        return;
    }
    
    if(count)
    {
        players[index] = true;
        split(index + 1, count - 1);
    }
    
    players[index] = false;
    split(index + 1, count);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < MAX; i++)
        players[i] = false;
    
    std::cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> S[i][j];
    
    split(0, N / 2);
    
    std::cout << min << '\n';
    
    return 0;
}
*/
/*
2020-02-21
Lee Min Keon
Baekjoon Online Judge #1904 stack memory overflow
mkleeboy3@naver.com
*/
/*
#include <iostream>
#include <vector>

#define MAX 15746

int N;
std::vector<unsigned short int> DP[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    for(int i = 0; i < MAX; i++)
    {
        DP[i].reserve(MAX - i);
        for(int j = 0; j < MAX - i; j++)
            DP[i][j] = 1;
    }
    
    for(int i = 1; i < MAX; i++)
        for(int j = 0; j < MAX - i; j++)
            if(!j)
                DP[i][j] = (DP[i - 1][j + 1] * 2) % MAX;
            else
                DP[i][j] = (DP[i][j - 1] + DP[i - 1][(j + 1) % MAX]) % MAX;
    
    int i = 0, j = N, sum = 0;
    while(j >= 0)
    {
        if(i > j)
            sum += DP[j % MAX][(i - j) % MAX];
        else
            sum += DP[i % MAX][(j - i) % MAX];
        
        sum %= MAX;
        i += 1; j -= 2;
    }
    
    std::cout << sum << '\n';
    
    return 0;
}
*/
/*
2020-02-21
Lee Min Keon
Baekjoon Online Judge #1904 fibonnaci resolution
mkleeboy3@naver.com
*/
/*
#include <iostream>

int N, sum = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N;
    
    int prev = 1, prev_prev = 0;
    for(int i = 1; i <= N; i++)
    {
        sum = prev % 15746 + prev_prev % 15746;
        sum %= 15746;
        prev_prev = prev % 15746;
        prev = sum % 15746;
    }
    
    std::cout << sum << '\n';
    
    return 0;
}
*/
/*
2020-03-08
Lee Min Keon
Baekjoon Online Judge #5543
mkleelboy3@naver.com
*/
/*
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int total = -1 * 50;
    
    int min = 3000;
    for(int i = 0; i < 3; i++)
    {
        int input;
        std::cin >> input;
        
        if(input < min)
            min = input;
    }
    
    total += min;
    
    min = 3000;
    for(int i = 0; i < 2; i++)
    {
        int input;
        std::cin >> input;
        
        if(input < min)
            min = input;
    }
    
    std::cout << total + min;
}
*/
/*
2020-03-11
Lee Min Keon
Baekjoon Online Judge #1009
mkleeboy3@naver.com
*/
/*
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tc;
    std::cin >> tc;
    
    while(tc--)
    {
        int a, b;
        std::cin >> a >> b;

        int result = 1;
        
        for(int i = 0; i < b; i++)
        {
            if(result >= 10)
                result /= 10;
            
            result *= a;
            result %= 10;
        }
        
        if(result == 0)
            std::cout << 10 << '\n';
        else
            std::cout << result << '\n';
    }
    
    return 0;
}
*/
/*
2020-03-15
Lee Min Keon
Baekjoon Online Judge #1247
mkleeboy3@naver.com
*/

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int tc = 0; tc < 3; tc++)
    {
        int N;
        std::cin >> N;
        
        char sign = 0;
        
        for(int n = 0; n < N; n++)
        {
            long long int num;
            std::cin >> num;
            
            
            
        }
    }
}






















































































































