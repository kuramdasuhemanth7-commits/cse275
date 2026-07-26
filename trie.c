#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord = 0;
    return node;
}

void insert(TrieNode* root, const char* word) {
    if (root == NULL || word == NULL) {
        return;
    }
    
    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET_SIZE) {
            continue;
        }
        
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

int search(TrieNode* root, const char* word) {
    if (root == NULL || word == NULL) {
        return 0;
    }
    
    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET_SIZE || current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}

int startsWith(TrieNode* root, const char* prefix) {
    if (root == NULL || prefix == NULL) {
        return 0;
    }
    
    TrieNode* current = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = tolower(prefix[i]) - 'a';
        if (index < 0 || index >= ALPHABET_SIZE || current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return 1;
}

void deleteWord(TrieNode* root, const char* word) {
    if (root == NULL || word == NULL) {
        return;
    }
    
    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET_SIZE || current->children[index] == NULL) {
            return;
        }
        current = current->children[index];
    }
    current->isEndOfWord = 0;
}

void freeTrieNode(TrieNode* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            freeTrieNode(node->children[i]);
        }
    }
    free(node);
}

void freeTrie(TrieNode* root) {
    freeTrieNode(root);
}

void printTrieHelper(TrieNode* node, char* word, int level) {
    if (node == NULL) {
        return;
    }
    
    if (node->isEndOfWord) {
        word[level] = '\0';
        printf("%s\n", word);
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            word[level] = 'a' + i;
            printTrieHelper(node->children[i], word, level + 1);
        }
    }
}

void printTrie(TrieNode* root) {
    if (root == NULL) {
        return;
    }
    char word[256];
    printTrieHelper(root, word, 0);
}

int main() {
    TrieNode* root = createNode();
    
    
    insert(root, "hello");
    insert(root, "world");
    insert(root, "help");
    insert(root, "heap");
    insert(root, "cat");
    insert(root, "car");
    
    
    printf("Searching for 'hello': %s\n", search(root, "hello") ? "Found" : "Not found");
    printf("Searching for 'hell': %s\n", search(root, "hell") ? "Found" : "Not found");
    printf("Searching for 'world': %s\n", search(root, "world") ? "Found" : "Not found");
    printf("Searching for 'word': %s\n", search(root, "word") ? "Found" : "Not found");
    
    
    printf("\nPrefix 'he': %s\n", startsWith(root, "he") ? "Yes" : "No");
    printf("Prefix 'ca': %s\n", startsWith(root, "ca") ? "Yes" : "No");
    printf("Prefix 'dog': %s\n", startsWith(root, "dog") ? "Yes" : "No");
    
    
    printf("\nAll words in Trie:\n");
    printTrie(root);
    
    
    printf("\nDeleting 'help'...\n");
    deleteWord(root, "help");
    printf("Searching for 'help' after deletion: %s\n", search(root, "help") ? "Found" : "Not found");
    
    // Free memory
    freeTrie(root);
    
    return 0;
}
