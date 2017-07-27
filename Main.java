package com.company;
import java.util.Scanner;

public class Main {
    /*
    clients to test the graph api.
     */
    static private int vertices;
    static Scanner sc = new Scanner(System.in);
    static Graph g;
    //compute the degree of v
    public static int degree(Graph G, int v) {
        return G.adj(v).size();
    }

    //compute the maximum degree of the vertices
    public static int maxDegree(Graph G) {
        int max = 0;
        for (int i = 0; i < G.V(); i++)
            if (degree(G, i) > max)
                max = degree(G, i);
        return max;
    }

    //number of self loops in a graph
    public static int numberOfSelfLoops(Graph G) {
        int count = 0;
        for (int v = 0; v < G.V(); v++)
            for (int w : G.adj(v))
                if (v == w) count++;
        return count / 2;
    }

    public static void printEdges(Graph G){
        for (int v=0;v<G.V();v++)
            for (int w:G.adj(v))
                System.out.println(v+" - "+w);
    }


    public static int menu(){
        System.out.println("OPERATIONS MENU");
        System.out.println("1 Add an edge to graph");
        System.out.println("2 Compute the degree of a vertex");
        System.out.println("3 Compute the maximum degree of the vertices");
        System.out.println("4 Compute number of self loops in a graph");
        System.out.println("5 Compute the number of edges in the graph");
        System.out.println("6 Print edges in the graph");
        System.out.println("7 Enter DFS menu");
        System.out.println("8 Exit");

        return sc.nextInt();
    }
    public static int dfsMenu(){
        System.out.println("OPERATIONS MENU");
        System.out.println("1 Check if the graph has a path to a vertex from the source");
        System.out.println("2 Print the path from the source to a vertex");
        System.out.println("3 Exit");
        return sc.nextInt();
    }

    public static void main(String[] args) {
        System.out.println("Welcome to graph Api test");
        System.out.println("Create a new graph");
        System.out.println("Number of vertices = ");
        vertices = sc.nextInt();
        g =new Graph(vertices);
        while (true)
            switch (menu()) {
            case 1:
                System.out.println("Enter vertex 1");
                int v1 = sc.nextInt();
                System.out.println("Enter vertex 2");
                int v2 = sc.nextInt();
                g.addEdge(v1,v2);
                break;
            case 2:
                System.out.println("Enter vertex number");
                int vno = sc.nextInt();
                System.out.println("the degree of vertex "+vno+" is:"+ degree(g,vno));
                break;
            case 3:
                System.out.println("the maximum degree of vertices in the graph is:"+ maxDegree(g));
               break;
            case 4:
                System.out.println("the number of self loops in the graph is:"+ numberOfSelfLoops(g));
                break;
            case 5:
                System.out.println("the number of edges in the graph are: "+g.E());
                break;
            case 6:
                System.out.println("The edges in the graph are:");
                printEdges(g);
                break;
            case 7:
                while (true){
                    boolean exit = false;
                    System.out.println("Enter a source vertex to traverse from:");
                    DepthFirstSearch df = new DepthFirstSearch(g,sc.nextInt());
                    switch (dfsMenu()){
                        case 1:
                            System.out.println("Enter the vertex in question: ");
                            int v = sc.nextInt();
                            System.out.println(df.hasPathTo(v));
                            break;
                        case 2:
                            System.out.println("Enter the vertex in question: ");
                            int vertex = sc.nextInt();
                            if(df.hasPathTo(vertex)){
                                for (int i:df.pathTo(vertex))
                                    System.out.print(i);
                            }else System.out.println("There is no path to that vertex");
                            break;
                        case 3:
                            exit = true;
                    }
                    if (exit)break;
                }
                break;
            default:
        }
    }

}

