import java.util.Arrays;

public class Lin {
    private final Vector[] base;
    private final Vector[] basis;

    public Lin(Vector... base) {
        this.base = base;
        this.basis = Vector.linearIndependence(base);
    }

    public Lin() {
        this.base = null;
        this.basis = null;
    }

    public Vector[] getBase() {
        return base;
    }

    public Vector getVector(double... alphas) {
        assert this.base != null;
        int size = this.base[0].size();
        double[] c = new double[size];
        Vector result = new Vector(c);
        double[] newAlphas = Arrays.copyOf(alphas, base.length);
        for (int i = 0; i < base.length; i++) {
            if (newAlphas[i] == 0) {
                continue;
            }
            result = result.add(this.base[i].multiply(newAlphas[i]));
        }
        return result;
    }

    public Lin setBase(Vector... newBase) {
        return new Lin(newBase);
    }

    public Vector[] getBasis() {
        return basis;
    }

    public Vector[] getOrthogonalBasis() {
        assert base == null;
        Vector[] orthogonalBasis = new Vector[basis.length];
        for (int i = 0; i < basis.length; i++) {
            orthogonalBasis[i] = basis[i];
            for (int j = 0; j < i; j++) {
                double numerator = (orthogonalBasis[j].
                        scalarMultiply(basis[i]));
                double denominator = (orthogonalBasis[j].
                        scalarMultiply(orthogonalBasis[j]));
                double alpha = (-1) * (numerator / denominator) ;
                orthogonalBasis[i] =
                        orthogonalBasis[i].add(orthogonalBasis[j].multiply(alpha));
            }

        }
        return orthogonalBasis;
    }

    public boolean equals(Lin l) {
        Vector[] basisL = l.getBasis();
        assert basis.length == basisL.length;
        assert basis[0].size() == basisL[0].size();
        for (int i = 0; i < basisL.length; i++) {
            if (!this.contains(basisL[i])) {
                return false;
            }
        }
        for (int i = 0; i < basis.length; i++) {
            if (!l.contains(basis[i])) {
                return false;
            }
        }
        return true;
    }

    public boolean contains(Vector v) {
        assert this.base != null;
        assert this.base[0].size() == v.size();
        Vector[] vectors = new Vector[basis.length + 1];
        vectors[0] = v;
        for (int i = 1; i < vectors.length; i++) {
            vectors[i] = basis[i - 1];
        }
        return Vector.linearIndependence(vectors).length != vectors.length;
    }

    @Override
    public String toString() {
        String res = "Lin (\n";
        assert base != null;
        for (Vector vector : base) {
            res += (vector.toString() + "\n");
        }
        res += ")";
        return res;
    }


}