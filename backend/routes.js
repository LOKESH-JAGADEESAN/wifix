// routes.js
const express = require('express');
const router = express.Router();

// Dummy data store
let dataStore = [];

// GET route to retrieve data from the server
router.get('/data', (req, res) => {
  res.json(dataStore);
});

// POST route to receive data from the ESP32
router.post('/data', (req, res) => {
  const { message } = req.body;

  if (!message) {
    return res.status(400).json({ error: 'Message is required' });
  }

  // Store the message in dataStore
  dataStore.push({ message, timestamp: new Date() });
  
  console.log(`Received from ESP32: ${message}`);
  
  res.status(200).json({ success: true, message: 'Data received' });
});

module.exports = router;
