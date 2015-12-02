
class Matrix {

public:

	Matrix(u_int n) {

		m_elements = new double[n][n];

	}

	double operator [](u_int x,u_int y) {

		return m_elements[x][y];

	}

private:

	double* m_elements;


};


int main( int argc, char** argv) {


	Matrix m(10);


}