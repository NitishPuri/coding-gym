//##
// Populate index.html
//##

function createTreeView_(data, container) {
    console.log('Creating tree view', data);
    container.empty();
    let ul = $('<ul class="list-group"></ul>');

    for (const [key, item] of Object.entries(data)) {
        console.log(key, item);
        const isCategory = !item['name'];

        let li = $('<li class="list-group-item"></li>');
        
        if (isCategory) {
            let childrenContainer = $('<ul class="list-group"></ul>');
            let d = $('<div></div>')
            
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

$(document).ready(function () {
    console.log('Setting up search');
    // Setup search.

    $('#search_input').on('keyup', function () {
        const value = $(this).val().toLowerCase();
        // show all the elements
        $('#list-view li').show();
        if (value == '') return;
        $('#list-view li').filter(function () {
            const text = $(this).text().toLowerCase();
            return text.indexOf(value) === -1;
        }).hide();
    });

    console.log('Search setup');

    // Read JSON
    // $.getJSON("static/index.json", process_data_json);
    $.get('static/index.json', (data) => {
        console.log('Processing JSON');
        createTreeView(data, $('#list-view'));
    });
});
