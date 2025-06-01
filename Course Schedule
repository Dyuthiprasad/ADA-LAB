#include <stdbool.h>

bool dfs(int course, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* visited, int numCourses) {
    if (visited[course] == 1) {
        return false;
    }
    if (visited[course] == 2) {
        return true;
    }

    visited[course] = 1;

    for (int i = 0; i < prerequisitesSize; i++) {
        if (prerequisites[i][0] == course) {
            int nextCourse = prerequisites[i][1];
            if (!dfs(nextCourse, prerequisites, prerequisitesSize, prerequisitesColSize, visited, numCourses)) {
                return false;
            }
        }
    }

    visited[course] = 2;
    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int visited[numCourses];
    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, prerequisites, prerequisitesSize, prerequisitesColSize, visited, numCourses)) {
                return false;
            }
        }
    }

    return true;
}
