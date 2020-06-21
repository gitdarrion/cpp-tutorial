
class matrix {
	public:
		int p;
		int q;
		int **A;//matrix of p by q
		int **B;//matrix of q by p
		int **AB;//matrix of p by p (=A*B)
		//int **BA;//matrix of q by q (=B*A)
		void printMatrix(int **m, int a, int b);
		void startmatrix(int a, int b);
		void generateMatrixA();
		void generateMatrixB(); 
		void computeProducts(int i, int j, int k);
		void printallmatrices();
		~matrix();
};

void* threadProduct(void* param); 
