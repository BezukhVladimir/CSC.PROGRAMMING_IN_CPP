void swap(int * matrix[],
          const unsigned &first,
          const unsigned &second) {
    int * temp = matrix[first];
    matrix[first] = matrix[second];
    matrix[second] = temp;
}

void swap_min(int * matrix[],
              const unsigned &rows,
              const unsigned &cols) {
    unsigned min_row = 0,
             min_col = 0;

    for (unsigned i = 0; i != rows; ++i)
        for (unsigned j = 0; j != cols ; ++j)
            if (matrix[i][j] < matrix[min_row][min_col])
                min_row = i,
                min_col = j;
 
    if (min_row)
        swap(matrix, 0, min_row);      
}