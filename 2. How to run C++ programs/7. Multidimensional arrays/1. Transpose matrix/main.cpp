int ** createMatrix(const unsigned &rows,
                    const unsigned &cols) {
    int ** matrix  = new int * [rows];
    matrix[0] = new int[rows * cols];

    for (unsigned i = 1; i != rows; ++i)
        matrix[i] = matrix[i - 1] + cols;

    return matrix;
}

int ** transpose(const int * const * matrix,
                 const unsigned &rows,
                 const unsigned &cols) {
    int ** transponse_matrix = createMatrix(cols, rows);
    
    for (unsigned i = 0; i < rows; ++i)
        for (unsigned j = 0; j < cols; ++j)
            transponse_matrix[j][i] = matrix[i][j];
    
    return transponse_matrix;
}