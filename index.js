//##
// Populate index.html
//##

function createTreeView_(data, container) {
    // console.log('Creating tree view', data);
    container.empty();
    let ul = $('<ul class="list-group"></ul>');

    for (const [key, item] of Object.entries(data)) {
        // console.log(key, item);
        const isCategory = !item['name'];

        let li = $('<li class="list-group-item"></li>');

        if (isCategory) {
            let childrenContainer = $('<ul class="list-group"></ul>');
            let d = $('<div></div>');

            let toggle = $('<span></span>').text('+');
            d.append(toggle);
            d.append($('<span></span>').text(`  ${key}`));

            d.on('click', function () {
                childrenContainer.toggleClass('collapsed');
                li.toggleClass('active');
                toggle.text(toggle.text() === '+' ? '-' : '+');
            });
            li.append(d);

            childrenContainer.append(createTreeView_(item, childrenContainer));
            li.append(childrenContainer);

            li.addClass('tree-category');
            li.addClass('toggle');
        } else {
            let name = $('<a></a>').text(`${key}`).attr('href', item.path);
            li.append(name);
            let text = $('<span></span>').text(` - ${item.tags}   -   `);
            li.append(text);
            let url = $('<a></a>').attr('href', item.url).text(item.url);
            li.append(url);

            li.addClass('tree-item');
        }

        ul.append(li);
    }
    container.append(ul);
}

function createTreeView(data, container) {
    createTreeView_(data['index'], container);
}

function populateTags(data) {
    const difficultyCloud = $('#tag-cloud #difficulty');
    difficultyCloud.empty();

    const tagCloud = $('#tag-cloud #tags');
    tagCloud.empty();

    console.log('Populating tags', data['tags']);

    for (const [tag, count] of Object.entries(data['tags'])) {
        if (tag == 'easy' || tag == 'medium' || tag == 'hard') {
            const tagElement = $('<span></span>')
                .addClass('tag')
                .data('tag', tag)
                .text(`${tag} (${count})`);
            difficultyCloud.append(tagElement);
        } else {
            const tagElement = $('<span></span>')
                .addClass('tag')
                .data('tag', tag)
                .text(`${tag} (${count})`);
            tagCloud.append(tagElement);
        }
    }
}

function processCategoriesVisibility() {
    // Start from the deepest categories and work upward
    const categories = $('.tree-category').toArray().reverse();

    $(categories).each(function () {
        // Check if this category has any visible items
        const hasVisibleItems = $(this).find('.tree-item:visible').length > 0;
        const hasVisibleCategories =
            $(this).find('.tree-category:visible').length > 0;

        if (!hasVisibleItems && !hasVisibleCategories) {
            // This category is empty after filtering, hide it
            $(this).hide();
        } else {
            // This category has visible content, show it
            $(this).show();
        }
    });
}

function filterByTags() {
    const activeTags = $('.tag.active')
        .map(function () {
            return $(this).data('tag');
        })
        .get();

    if (activeTags.length === 0) {
        // Show all items if no tags selected
        $('.tree-item, .tree-category').show();
        return;
    }

    // Hide all items first
    $('.tree-item').hide();

    // Show only items that match selected tags
    $('.tree-item')
        .filter(function () {
            const text = $(this).text().toLowerCase();
            let to_show = false;
            activeTags.forEach((tag) => {
                if (text.indexOf(tag) !== -1) {
                    to_show = true;
                }
            });
            return to_show;
        })
        .show();

    processCategoriesVisibility();
}

function setupDarkMode() {
    // Check for saved theme preference or respect OS setting
    const prefersDarkScheme = window.matchMedia('(prefers-color-scheme: dark)');
    const storedTheme = localStorage.getItem('theme');

    // Apply theme based on stored preference or OS setting
    if (storedTheme === 'dark' || (!storedTheme && prefersDarkScheme.matches)) {
        document.body.classList.add('dark-theme');
    }

    // Theme toggle button click handler
    $('#theme-toggle').click(function () {
        document.body.classList.toggle('dark-theme');

        // Save preference to localStorage
        if (document.body.classList.contains('dark-theme')) {
            localStorage.setItem('theme', 'dark');
        } else {
            localStorage.setItem('theme', 'light');
        }
    });
}

$(document).ready(function () {
    console.log('Setting up search');
    // Setup search.

    $('#search_input').on('keyup', function () {
        const value = $(this).val().toLowerCase();
        // show all the elements
        $('#list-view li').show();
        if (value == '') return;
        $('#list-view li')
            .filter(function () {
                const text = $(this).text().toLowerCase();
                return text.indexOf(value) === -1;
            })
            .hide();

        processCategoriesVisibility();
    });

    console.log('Search setup');

    setupDarkMode();

    // Read JSON
    // $.getJSON("static/index.json", process_data_json);
    $.get('static/index.json', (data) => {
        console.log('Processing JSON');
        createTreeView(data, $('#list-view'));
        populateTags(data);

        // Tag cloud functionality
        $('.tag').on('click', function () {
            const tag = $(this).data('tag');
            // Toggle active class
            $(this).toggleClass('active');
            // Filter the list based on selected tags
            filterByTags();
        });
    });
});
