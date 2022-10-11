import os
import csv

source_dirs = ["leetcode"]


def extract_meta_info(filepath):
    with open(filepath) as source_file:
        url = source_file.readline()[2:].strip()
        tags = source_file.readline()[2:].strip()
        tags = tags.split(', ')
        tags = ";".join(tags)
        return url, tags
        


def write_data():
    all_tags = []
    with open('index.csv', 'w', newline='') as data:
        data_writer = csv.writer(data)
        data_writer.writerow(["name", "path", "url", "tags"])
        for source in source_dirs:
            for cat in os.listdir(source):
                cat_path = os.path.join(source, cat)
                for f in os.listdir(cat_path):
                    name = f.split('.')[0]
                    path = os.path.join(source, cat, f)
                    url, tags = extract_meta_info(path)
                    tags += ";" + source + ";" + cat
                    data_writer.writerow([name, path, url, tags])
                    all_tags.append(tags)
    
    tags = {}
    # process tags
    for tag in all_tags:
        for t in tag.split(';'):
            if t != '':
                tags[t] = tags.get(t, 0) + 1
    print(tags)
    with open('tags.csv', 'w', newline='') as data:
        data_writer = csv.writer(data)
        # data_writer.writerows(tags)
        for tag in tags:
            data_writer.writerow([tag, tags[tag]])



# extract_meta_info("leetcode\\array\\1-bit-and-2-bit-characters.cpp")
write_data()






