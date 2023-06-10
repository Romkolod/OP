#include <iostream>
#include <fstream>

using namespace std;

const int MAX_VERTICES = 100;

void create_matrix(int matrix[][MAX_VERTICES], int num_vertices, ifstream& in_file) {
    int vertex1, vertex2;
    while (in_file >> vertex1 >> vertex2) {
        matrix[vertex1][vertex2] = 1;
        matrix[vertex2][vertex1] = 1;
    }
}

void write_matrix(int matrix[][MAX_VERTICES], int num_vertices, ofstream& out_file) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            out_file << matrix[i][j] << " ";
        }
        out_file << endl;
    }
}

void create_list(int list[][MAX_VERTICES], int num_vertices, int matrix[][MAX_VERTICES]) {
    for (int i = 0; i < num_vertices; i++) {
        int count = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (matrix[i][j] == 1) {
                list[i][count] = j;
                count++;
            }
        }
    }
}

void write_list(int list[][MAX_VERTICES], int num_vertices, ofstream& out_file) {
    for (int i = 0; i < num_vertices; i++) {
        out_file << i << ": ";
        for (int j = 0; j < num_vertices; j++) {
            if (list[i][j] != -1) {
                out_file << list[i][j] << " ";
            }
        }
        out_file << endl;
    }
}

void create_sequence(int sequence[][2], int& num_edges, int matrix[][MAX_VERTICES], int num_vertices) {
    num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            if (matrix[i][j] == 1) {
                sequence[num_edges][0] = i;
                sequence[num_edges][1] = j;
                num_edges++;
            }
        }
    }
}

void write_sequence(int sequence[][2], int num_edges, ofstream& out_file) {
    for (int i = 0; i < num_edges; i++) {
        out_file << sequence[i][0] << " " << sequence[i][1] << endl;
    }
}

int main() {
    int num_vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES] = { 0 };
    int list[MAX_VERTICES][MAX_VERTICES] = { -1 };
    int sequence[MAX_VERTICES][2];
    int num_edges = 0;

    ifstream in_file("graph.txt");
    in_file >> num_vertices;

    create_matrix(matrix, num_vertices, in_file);
    in_file.close();

    ofstream out_file("matrix.txt");
    write_matrix(matrix, num_vertices, out_file);
    out_file.close();

    create_list(list, num_vertices,matrix);

    out_file.open("list.txt");
    write_list(list, num_vertices, out_file);
    out_file.close();

    create_sequence(sequence, num_edges, matrix, num_vertices);

    out_file.open("sequence.txt");
    write_sequence(sequence, num_edges, out_file);
    out_file.close();

    return 0;
}