

vector<int> findValidSequence(vector<int>& currentSequence, vector<int>& remainingElements, int index) {
    if (index == currentSequence.size()) {
        return currentSequence;
    }

    if (currentSequence[index] != 0) {
        return findValidSequence(currentSequence, remainingElements, index + 1);
    }

    // Iterate from the biggest element to the smallest.
    for (int i = remainingElements.size() - 1; i > 0; i--) {
        if (remainingElements[i] == 0) {
            continue;
        }

        if (i != 1 && index + i < currentSequence.size() && currentSequence[index + i] == 0) {
            /*
                Mark 'currentSequence[index]' and 'currentSequence[index + i]' as 'i',
                mark the current element as used, and then try to create the remaining sequence.
            */
            currentSequence[index] = i;
            currentSequence[index + i] = i;
            remainingElements[i] = 0;

            vector<int> tempSequence = findValidSequence(currentSequence, remainingElements, index + 1);

            if (!tempSequence.empty()) {
                return tempSequence;
            }

            // If the sequence could not be created, mark the current element as unused.
            remainingElements[i] = 1;
            currentSequence[index] = 0;
            currentSequence[index + i] = 0;
        }

        if (i == 1) {
            /*
                Mark 'currentSequence[index]' as 'i', mark the current element as used,
                and then try to create the remaining sequence.
            */
            currentSequence[index] = i;
            remainingElements[i] = 0;

            vector<int> tempSequence = findValidSequence(currentSequence, remainingElements, index + 1);

            if (!tempSequence.empty()) {
                return tempSequence;
            }

            // If the sequence could not be created, mark the current element as unused.
            remainingElements[i] = 1;
            currentSequence[index] = 0;
        }
    }

    // Return an empty vector if a valid sequence could not be found.
    return {};
}

vector<int> validSequence(int n) {
    vector<int> sequence(2 * n - 1, 0);
    vector<int> remainingElements(n + 1, 1);

    return findValidSequence(sequence, remainingElements, 0);
}
