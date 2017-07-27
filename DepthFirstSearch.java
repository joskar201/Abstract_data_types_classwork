package com.company;

import java.util.ArrayList;

/**
 * Created by josh on 7/26/17.
 */
public class DepthFirstSearch {
    private boolean[] marked;//remember where you have been
    private int[] edgeTO;//where you were before here
    private int S;

    public DepthFirstSearch(Graph G, int s){
        int no_vertices = G.V();
        S = s;
        marked = new boolean[no_vertices];
        for (int i=0;i<no_vertices;i++)
            marked[i] = false;
        edgeTO = new int[no_vertices];
        for (int i=0;i<no_vertices;i++)
            edgeTO[i] = 0;
        dfs(G,s);

    }
    private void dfs(Graph G, int v){
        marked[v] = true;
        for (int w :G.adj(v))
            if (!marked[w]){
            dfs(G,w);
            edgeTO[w] = v;
            }
    }

    public boolean hasPathTo(int v){
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v){
        ArrayList<Integer> pathto = new ArrayList<>();
        for (int i=0;i<v;i++){
            pathto.add(i);
        }
        return pathto;
    }
}
