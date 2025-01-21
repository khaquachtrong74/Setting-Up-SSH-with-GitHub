window.onload = function () {
    // State management
    let completedItems = new Set(JSON.parse(localStorage.getItem('completedItems')) || []);

    // Functions
    function toggleComplete(event) {
        const item = event.currentTarget;
        const itemId = item.getAttribute('data-item');

        if (item.classList.contains('completed')) {
            item.classList.remove('completed');
            completedItems.delete(itemId);
        } else {
            item.classList.add('completed');
            completedItems.add(itemId);
        }

        // Save to localStorage
        localStorage.setItem('completedItems', JSON.stringify([...completedItems]));

        // Update progress bar
        updateProgress();
    }

    function updateProgress() {
        const totalItems = document.querySelectorAll('.tree-item').length;
        const completedCount = completedItems.size;
        const progressPercentage = (completedCount / totalItems) * 100;

        const progressFill = document.getElementById('progressFill');
        const progressText = document.getElementById('progressText');

        progressFill.style.width = `${progressPercentage}%`;
        progressText.textContent = `${Math.round(progressPercentage)}% Complete`;
    }

    function resetProgress() {
        if (confirm('Are you sure you want to reset all progress?')) {
            completedItems.clear();
            localStorage.removeItem('completedItems');
            document.querySelectorAll('.tree-item').forEach(item => {
                item.classList.remove('completed');
            });
            updateProgress();
        }
    }

    // Initialize all items
    document.querySelectorAll('.tree-item').forEach(item => {
        // Add click handler
        item.addEventListener('click', toggleComplete);

        // Restore saved state
        const itemId = item.getAttribute('data-item');
        if (completedItems.has(itemId)) {
            item.classList.add('completed');
        }
    });

    // Add reset button event listener
    document.getElementById('reset-button').addEventListener('click', resetProgress);

    // Initial progress update
    updateProgress();
};