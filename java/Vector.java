import java.util.Arrays;

public class Vector {
    private final double[] data;

    public Vector(double... data) {
        this.data = data;
    }

    Vector() {
        this.data = new double[0];
    }

    public int size() {
        return data.length;
    }

    public double[] getData() {
        return Arrays.copyOf(data, data.length);
    }

    public Vector add(Vector v) {
        assert v.size() == data.length;
        double[] newData = new double[data.length];
        for (int i = 0; i < size(); i++) {
            newData[i] = data[i] + v.getData()[i];
        }
        return new Vector(newData);
    }

    public double scalarMultiply(Vector v) {
        assert v.size() == data.length;
        double sum = 0;
        for (int i = 0; i < size(); i++) {
            sum += (data[i] * v.getData()[i]);
        }
        return sum;
    }

    public boolean equals(Vector v) {
        assert v.size() == data.length;
        return Arrays.equals(data, v.data);
    }

    public Vector multiply(double alpha) {
        double[] newData = new double[data.length];
        for (int i = 0; i < size(); i++) {
            newData[i] = data[i] * alpha;
        }
        return new Vector(newData);
    }

    @Override
    public String toString() {
        return Arrays.toString(this.data);
    }

    public static Vector[] linearIndependence(Vector... vectors) {
        int rows = vectors.length;
        int cols = vectors[0].size();
        double EPSILON = 1e-10;

        for (int i = 1; i < rows; i++) {
            assert vectors[i].size() == cols;
        }

        double[][] matrix = new double[rows][cols];
        int[] indices = new int[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = Arrays.copyOf(vectors[i].getData(), cols);
            indices[i] = i;
        }

        int step = 0;
        for (int col = 0; col < cols; col++) {
            int niceRow = -1;
            for (int row = step; row < rows; row++) {
                if (Math.abs(matrix[row][col]) > EPSILON ) {
                    niceRow = row;
                    break;
                }
            }

            if (niceRow == -1) continue;

            double[] tmpRow = matrix[step];
            matrix[step] = matrix[niceRow];
            matrix[niceRow] = tmpRow;

            int tmpIndex = indices[step];
            indices[step] = indices[niceRow];
            indices[niceRow] = tmpIndex;

            double leadingElement = matrix[step][col];
            for (int j = col; j < cols; j++) {
                matrix[step][j] /= leadingElement;
            }

            for (int row = step + 1; row < rows; row++) {
                double factor = matrix[row][col];
                for (int j = col; j < cols; j++) {
                    matrix[row][j] -= factor * matrix[step][j];
                }
            }

            step++;
        }

        Vector[] result = new Vector[step];
        for (int i = 0; i < step; i++) {
            result[i] = vectors[indices[i]];
        }
        return result;
    }

}