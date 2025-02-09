//##
// Populate index.html
//##

function createTreeView_(data, container) {
    console.log('Creating tree view', data);
    container.empty();
    let ul = $('<ul></ul>');

    for (const [key, item] of Object.entries(data)) {
        console.log(key, item);
        const isCategory = !item['name'];

        let li = $('<li></li>');
        let childrenContainer = $('<ul></ul>');
        console.log('123', childrenContainer);

        if (isCategory) {
            let toggle = $(
                '<button class="btn btn-outline-primary"></button>'
            ).text('+');
            li.append(toggle);
            toggle.on('click', function () {
                console.log(childrenContainer[0].classList);
                childrenContainer.toggleClass('nested');
                toggle.text(toggle.text() === '+' ? '-' : '+');
            });

            li.append($('<span></span>').text(`  ${key}`));
            console.log('Finding children for', key);
            childrenContainer.append(createTreeView_(item, childrenContainer));
        } else {
            let text = $('<span></span>').text(`${key} - ${item.tags}   -   `);
            li.append(text);
            let url = $('<a></a>').attr('href', item.url).text(item.url);
            li.append(url);
        }

        li.append(childrenContainer);
        ul.append(li);
    }
    container.append(ul);
}

function createTreeView(data, container) {
    createTreeView_(data['index'], container);
}

$(document).ready(function () {
    console.log('Setting up search');
    // Setup search.

    $('#search_input').on('keyup', function () {
        const value = $(this).val().toLowerCase();

        // show all the elements
        $('#list-view li').show();

        console.log('Searching, ', value);
        if (value == '') return;

        $('#list-view li')
            .filter(function () {
                const text = $(this).text().toLowerCase();
                return text.indexOf(value) === -1;
            })
            .hide();
    });

    console.log('Search setup');

    // Read JSON
    // $.getJSON("static/index.json", process_data_json);
    $.get('static/index.json', (data) => {
        console.log('Processing JSON');
        createTreeView(data, $('#list-view'));
    });
});
