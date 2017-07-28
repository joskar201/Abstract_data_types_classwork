package com.company;

import java.util.ArrayList;
import java.util.List;

public class Graph {
    private final int V;
    private ArrayList<Integer>[] adj;//vertex indexed array of adjacency lists

    public Graph(int v) {
        this.V = v;
        adj = (ArrayList<Integer>[]) new ArrayList[v];
        for (int i=0; i < v; i++)
            adj[i] = new ArrayList<>();
    }

    public void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v);
    }

    public void deleteVertex(int v){
        adj[v] = null;
    }
    public List<Integer> adj(int v) {
        return adj[v];
    }
    public int V(){
        return this.V;
    }
    //find a faster way to do this
    public int E(){
        int count = 0;
        for (int v=0;v<this.V;v++)
            for (int w:this.adj(v))
                count++;
        return count/2;
    }
}
