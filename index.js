
//##
// Populate index.html
//##

function process_data_csv(data) {
    console.log("Processing csv")
    const all_lines = data.split(/\r\n|\n/);
    const headers = all_lines[0].split(',');
    let lines = [];

    // Read all the lines
    for (let i = 1; i < all_lines.length; i++) {
        let line = all_lines[i].split(',');
        // console.log(line)
        if (line.length == headers.length) {
            let obj = {};
            for (let j = 0; j < headers.length; j++) {
                obj[headers[j]] = line[j]
            }
            lines.push(obj)
        }
    }

    let keys = ['Name', 'Problem Statement', 'Tags']
    $('#contents-header').append(keys.map((k) => $(`<th>${k}</th>`)))

    // Add entries to list
    function createListItem(line) {
        let li = $('<tr></tr>');
        li.append($('<td></td>').append(`<a href=${line.path}>${line.name}</a>`))
        li.append($('<td></td>').append(`<a href=${line.url}>${line.url}</a>`))
        // li.append($('<td></td>').append(`<a href=${line.url}>${line.name}</a>`))        
        li.append($('<td></td>').append(`<span>${line.tags}</span>`))
        return li
    }
    $('#contents').append(lines.map(createListItem));

}

function createTreeView(data, container) {
    console.log("Creating tree view", data)
    container.empty();
    data.forEach(item => {
        let li = $('<li></li>').addClass('tree-item');
        let toggle = $('<span></span>').addClass('toggle').text('▶');
        let text = $('<span></span>').addClass('item-text').text(`${item.platform} - ${item.title} (${item.difficulty})`);
        let childrenContainer = $('<ul></ul>').addClass('nested');

        if (item.children && item.children.length > 0) {
            li.append(toggle);
            toggle.on('click', function () {
                childrenContainer.toggle();
                toggle.text(toggle.text() === '▶' ? '▼' : '▶');
            });
        }
        li.append(text);
        childrenContainer.append(createTreeView(item.children || [], childrenContainer));
        li.append(childrenContainer);
        container.append(li);
    });
}


$(document).ready(function () {
    console.log("Setting up search")
    // Setup search.
    $("#search_input").on("keyup", function () {
        const value = $(this).val().toLowerCase();
        $("#contents tr").filter(function () {
            $(this).toggle($(this).text().toLowerCase().indexOf(value) > -1)
        });
    });
    console.log("Search setup")

    // Read CSV.
    $.get("static/index.csv", (data) => {
        console.log("Processing CSV");
        process_data_csv(data);
    })
    // $.get({
    //     url: "static/index.csv",
    //     dataType: "text",
    //     success: process_data_csv
    // })

    // Read JSON
    // $.getJSON("static/index.json", process_data_json);
    $.get("static/index.json", (data) => {
        console.log("Processing JSON");
        createTreeView(data, $('#contents'));
    })
    

});
