const fs = require('fs');
const path = require('path');

const sourceDirs = ["leetcode", "hackerrank"];

function extractMetaInfo(filepath) {
    const sourceFile = fs.readFileSync(filepath, 'utf-8').split('\n');
    let url = sourceFile[0].slice(2).trim();
    if (url.endsWith('/')) {
        url = url.slice(0, -1);
    }
    const tagsLine = sourceFile[1].slice(2).trim();
    const tags = tagsLine.split(', ').join(';');
    return { url, tags };
}


async function writeDataJsonRecursive() {
    const indexData = {};
    const allTags = {};

    function collectData(sourcePath, sourceName) {
        console.log('Collecting data from', sourceName, sourcePath);    
        
        const collectedData = {};        
        let allCount = 0;
        const directory_entries = fs.readdirSync(sourcePath);
        directory_entries.forEach(entryName => {            
            const entryPath = path.join(sourcePath, entryName);            
            const stats = fs.statSync(entryPath);
            if (stats.isDirectory()) {                
                // Recursively collect data from this directory
                let data = collectData(entryPath, entryName);
                collectedData[entryName] = data[0];
                allCount += data[1];
            } else {
                const { url, tags } = extractMetaInfo(entryPath);
                const name = path.parse(entryName).name;

                // Add to index data
                collectedData[name] = ({ name, path: entryPath, url, tags });
                tags.split(';').forEach(tag => {
                    allTags[tag] = (allTags[tag] || 0) + 1;
                });
                allCount++;
            }
        });

        console.log('Collected data from', sourcePath, Object.keys(collectedData).length);
        // add source as a category if not already present
        allTags[sourceName] = (allTags[sourceName] || 0) + allCount;
        return [collectedData, allTags[sourceName]];
    }

    // Start collecting data from the source directories
    sourceDirs.forEach(source => {
        indexData[source] = collectData(source, path.parse(source).name)[0]
    });

    // Create the JSON structure
    const outputData = {
        index: indexData,
        tags: allTags
    };

    // Write to JSON file
    const outputFilePath = path.join('static', 'index.json');
    fs.writeFileSync(outputFilePath, JSON.stringify(outputData, null, 2));

    console.log(`Index created at ${outputFilePath}`);
}

writeDataJsonRecursive().then(() => {
    console.log('Data extraction complete.');
}).catch(err => {
    console.error('Error extracting data:', err);
});