import java.util.Arrays;

public class ExampleOfUse {
    public static void main(String[] args) {
        // Create some basic vectors
        Vector v1 = new Vector(1, 0, 0);
        Vector v2 = new Vector(0, 1, 0);
        Vector v3 = new Vector(1, 1, 1);
        Vector v4 = new Vector(2, -1, 0);

        // Create a linear span from three vectors
        Lin lin = new Lin(v1, v2, v3, v4);

        // Print the original base
        System.out.println("Base:");
        System.out.println(Arrays.toString(lin.getBase()));

        // Print the computed basis (linearly independent subset)
        System.out.println("\nLinearly Independent Basis:");
        System.out.println(Arrays.toString(lin.getBasis()));

        // Print the orthogonal basis using Gram-Schmidt process
        System.out.println("\nOrthogonal Basis:");
        System.out.println(Arrays.toString(lin.getOrthogonalBasis()));

        // Generate a linear combination of basis vectors
        Vector linComb = lin.getVector(1, 2, -1, 2);
        System.out.println("\nLinear Combination (1*v1 + 2*v2 - 1*v3 + 2*v4):");
        System.out.println(linComb);

        // Check if a vector is in the span
        Vector test = new Vector(2, 3, 0);
        System.out.println("\nDoes the span contain (2, 3, 0)?");
        System.out.println(lin.contains(test));

        // Create another linear span and compare
        Lin lin2 = new Lin(
                new Vector(2, 0, 0),
                new Vector(0, 2, 0),
                new Vector(3, 3, 3)
        );
        System.out.println("\nLin2: " + lin2);
        System.out.println("\nIs lin equal to lin2?");
        System.out.println(lin.equals(lin2));
    }
}
