const express = require('express');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = 8000;
const FILES_DIR = path.join(__dirname, 'files');

// Route 1: Show list of files
app.get('/', (req, res) => {
    fs.readdir(FILES_DIR, (err, files) => {
        if (err) {
            return res.status(500).send('Unable to scan directory.');
        }

        let fileLinks = files.map(file => {
            return `<li><a href="/${file}">${file}</a></li>`;
        }).join('');

        res.send(`<h2>Files:</h2><ul>${fileLinks}</ul>`);
    });
});

// Route 2: Download file when accessed via filename
app.get('/:filename', (req, res) => {
    const filePath = path.join(FILES_DIR, req.params.filename);

    if (fs.existsSync(filePath)) {
        res.download(filePath); // automatic download
    } else {
        res.status(404).send('File not found');
    }
});

app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
