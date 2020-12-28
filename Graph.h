#pragma once

#include "Sequence.h"
#include "ListSequence.h"
#include <iostream>
using namespace std;
struct vertex {
    int power;
    int num;
    int color = -1;
};

class graph {
private:
    list_sequence<int*> *arcs;
public:
    graph(int size, int** ribs) {
        arcs = new list_sequence<int*>();
        for (int i=0; i<size; i++) {
            int* temp = new int[size];
            for (int j=0; j<size; j++) {
                temp[j] = ribs[i][j];
            }
            arcs->prepend(temp);
        }
    }

    vertex* sort_vertices() {
        auto arr = new int[arcs->get_length()];
        for (int i=0; i<arcs->get_length(); i++) {
            arr[i] = 0;
            for (int j=0; j<arcs->get_length(); j++) {
                arr[i] += arcs->get(i)[j];
            }
        }
        auto vertices = new vertex[arcs->get_length()];
        for (int i=0; i<arcs->get_length(); i++) {
            vertices[i].power = arr[i];
            vertices[i].num = i;
        }
        vertex temp;
        for (int i = 0; i < arcs->get_length() - 1; i++) {
            for (int j = 0; j < arcs->get_length() - i - 1; j++) {
                if (vertices[j].power < vertices[j + 1].power) {
                    temp.power = vertices[j].power;
                    temp.num = vertices[j].num;
                    vertices[j].power = vertices[j + 1].power;
                    vertices[j].num = vertices[j + 1].num;
                    vertices[j + 1].power = temp.power;
                    vertices[j + 1].num = temp.num;
                }
            }
        }
        return vertices;
    }

    int shortest_way(int first, int last) {
        auto queue = list_sequence<int>();
        auto tagged = new bool[arcs->get_length()];
        for (int i=0; i<arcs->get_length(); i++) {
            tagged[i] = false;
        }
        int depth = 0;
        int vertex_ = first;
        tagged[vertex_] = true;
        queue.prepend(vertex_);
        while (queue.get_length() != 0) {
            depth += 1;
            for (int i=0; i<arcs->get_length(); i++) {
                if ((arcs->get(vertex_))[i] == 1 && !tagged[i]) {
                    queue.prepend(i);
                    tagged[i] = true;
                    if (i == last)
                        return depth;
                }
            }
            queue.remove_at(0);
            if (queue.get_length() != 0)
                vertex_ = queue.get(0);
        }
        return -1;
    }

    int* shortest_way_path(int first, int last) {
        int temp_vertex = first;
        if (shortest_way(first, last) == -1) {
            auto way = new int[1];
            way[0] = -1;
            return way;
        }
        auto way = new int[shortest_way(first, last) + 1];
        int counter = 0;
        way[0] = first;
        while (temp_vertex != last) {
            for (int i=0; i<arcs->get_length(); i++) {
                if (shortest_way(arcs->get(temp_vertex)[i], last) == (shortest_way(temp_vertex, last) - 1) && arcs->get(temp_vertex)[i] == 1) {
                    counter++;
                    temp_vertex = i;
                    way[counter] = i;
                    if (shortest_way(temp_vertex, last) == 1) {
                        way[counter+1] = last;
                        return way;
                    }
                    break;
                }

            }
        }
        return way;
    }

    int chromatic_number() {
        auto vertices = this->sort_vertices();
        int counter = arcs->get_length();
        int chromatic_number = 0;
        int real_color = -1;
        auto colors = new int[arcs->get_length()];
        while (counter != 0) {
            int color = -1;
            for (int i=0; i<arcs->get_length(); i++) {
                if (color == -1 && vertices[i].color == -1) {
                    real_color += 1;
                    color = real_color;
                    vertices[i].color = color;
                    colors[vertices[i].num] = color;
                    counter -= 1;
                    chromatic_number += 1;
                }
                else if (vertices[i].color == -1) {
                    int flag = 0;
                    for (int j=0; j<arcs->get_length(); j++) {
                        if (arcs->get(vertices[i].num)[j] == 1 && colors[j] == color)
                            flag = 1;
                    }
                    if (flag == 0) {
                        vertices[i].color = color;
                        colors[vertices[i].num] = color;
                        counter -= 1;
                    }
                }
            }
        }
        return chromatic_number;
    }

    int power(int vertex_num) {
        int power = 0;
        for (int j=0; j<arcs->get_length(); j++) {
            power += arcs->get(vertex_num)[j];
        }
        return power;
    }

    void show_graph() {
        for (int i=0; i<arcs->get_length(); i++) {
            for (int j=0; j<arcs->get_length(); j++) {
                cout << (arcs->get(i))[j] << " ";
            }
            cout << endl;
        }
    }

};
