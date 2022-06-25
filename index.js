import fs from "fs";
import path, { dirname } from "path";

const unusedFolders = [
  ".git",
  ".github",
  "node_modules",
  "public",
  "src",
  "test",
];

const parseMarkdown = (filePath, title) => {
  let file = fs.readFileSync(filePath, "utf8");
  file = file.replace(new RegExp("<[^>]*>", "g"), "");
  file = file.replace(new RegExp("{", "g"), " { ");
  file = file.replace(new RegExp("}", "g"), " } ");

  let content = `---
layout: post
title: ${title}
date: ${new Date().toISOString()}
---

\`\`\`
${file} 
\`\`\`
`;
  return content;
};

const parseFolders = (folderPath) => {
  console.log(folderPath);
  const folderpaths = {
    items: [],
    prefixes: [],
  };
  const files = fs.readdirSync(folderPath);

  console.log(files);
  let markdowns = {};
  files.forEach((file) => {
    console.log(file);

    if (file.endsWith(".md")) {
      markdowns[file] = parseMarkdown(path.join(folderPath, file), folderPath);
    } else {
      const filePath = path.join(folderPath, file);
      const _file = fs.readFileSync(filePath, "utf8");
      // console.log(_file);
      markdowns["Code"] = `\`\`\`\n  ${_file} \n\`\`\``;
    }
  });
  // console.log(markdowns);

  if (markdowns["README.md"]) {
    const dir = `_posts`;
    if (!fs.existsSync(dir)) {
      fs.mkdirSync(dir);
    }
    let text = [markdowns["README.md"]];
    delete markdowns["README.md"];
    text = [
      ...text,
      ...Object.keys(markdowns).map((val) => `##${val}\n ${markdowns[val]}`),
    ].join("\n");

    fs.writeFile(
      `_posts/${new Date().getFullYear()}-${
        new Date().getUTCMonth() + 1
      }-${new Date().getUTCDate()}-${folderPath}.markdown`,
      text,
      (err) => {
        if (err) throw err;
        console.log("The file has been saved!");
      }
    );
  }
  return folderpaths;
};

const folderpaths = {
  path: "",
  name: "Resources",
  items: [],
  prefixes: [],
};

fs.readdirSync(dirname(""), { withFileTypes: true }).forEach((file) => {
  if (file.isDirectory() && !unusedFolders.includes(file.name)) {
    console.log(file);
    parseFolders(file.name);
  }
});

fs.writeFile("./index.json", JSON.stringify(folderpaths), (err) => {
  if (err) throw err;
  console.log("The file has been saved!");
});
